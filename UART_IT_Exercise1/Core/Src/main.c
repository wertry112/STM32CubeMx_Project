/* main.c - 修正版 */
#include "main.h"
#include "usart.h"
#include "gpio.h"
#include <string.h>
#include <stdint.h>

void SystemClock_Config(void);

/* --- 全局共享变量 --- */
volatile uint8_t rx_char = 0;        // 接收单字节（中断填充）
volatile uint8_t send_flag = 0;      // 0: 停止发送，1: 开始发送
volatile uint8_t status_changed = 0; // 主循环处理提示与首次发送
volatile uint8_t status_val = 0;     // 1:start, 2:stop, 3:error

/* --- 文本 --- */
static const char message[]    = "hello Windows\n";
static const char tips_error[] = "CommandError\n";
static const char tips_start[] = "Start.....\n";
static const char tips_stop[]  = "Stop......\n";

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART1_UART_Init();

  /* 启动接收中断（接收单字节） */
  HAL_UART_Receive_IT(&huart1, (uint8_t *)&rx_char, 1);

  uint32_t last_send_tick = HAL_GetTick(); // 发送时间控制（ms）

  while (1)
  {
    /* 若有状态变化（由中断设置），主循环负责打印提示并做首次发送 */
    if (status_changed)
    {
      if (status_val == 1) {               // start
        HAL_UART_Transmit(&huart1, (uint8_t *)tips_start, strlen(tips_start), 100);
        /* 立即发送一次 message，随后以 1s 间隔继续发送 */
        HAL_UART_Transmit(&huart1, (uint8_t *)message, strlen(message), 100);
        last_send_tick = HAL_GetTick();
      }
      else if (status_val == 2) {          // stop
        HAL_UART_Transmit(&huart1, (uint8_t *)tips_stop, strlen(tips_stop), 100);
      }
      else {                               // error
        HAL_UART_Transmit(&huart1, (uint8_t *)tips_error, strlen(tips_error), 100);
      }
      status_changed = 0;
    }

    /* 周期性发送（非阻塞，使用 HAL_GetTick） */
    if (send_flag)
    {
      uint32_t now = HAL_GetTick();
      if ((now - last_send_tick) >= 1000) {
        HAL_UART_Transmit(&huart1, (uint8_t *)message, strlen(message), 100);
        last_send_tick = now;
      }
    }

    /* 小延时以避免空转过多 CPU，且允许中断执行 */
    HAL_Delay(1);
  }
}

/* UART 接收完成回调（中断上下文） */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART1)
  {
    /* 忽略回车/换行，兼容上位机工具发送 "1\r\n" 的情况 */
    if (rx_char == '\r' || rx_char == '\n') {
      HAL_UART_Receive_IT(&huart1, (uint8_t *)&rx_char, 1);
      return;
    }

    /* 识别命令：支持 ASCII '1'/'0' 以及原始字节 0x01/0x00 */
    if (rx_char == '1' || rx_char == 1) {
      send_flag = 1;
      status_val = 1;   // start
      status_changed = 1;
    }
    else if (rx_char == '0' || rx_char == 0) {
      send_flag = 0;
      status_val = 2;   // stop
      status_changed = 1;
    }
    else {
      send_flag = 0;
      status_val = 3;   // error
      status_changed = 1;
    }

    /* 重新开启下一字节接收 */
    HAL_UART_Receive_IT(&huart1, (uint8_t *)&rx_char, 1);
  }
}

/* SystemClock_Config 和 Error_Handler 保持与你工程一致 */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) { Error_Handler(); }

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK) { Error_Handler(); }
}

void Error_Handler(void)
{
  __disable_irq();
  while (1) { }
}
