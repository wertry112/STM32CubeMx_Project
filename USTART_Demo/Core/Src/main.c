/* USER CODE BEGIN Includes */
#include "main.h"
#include "usart.h"
#include "gpio.h"

#include <string.h>
#include <stdint.h>

/* USER CODE END Includes */
void SystemClock_Config(void);
void Error_Handler(void);

/* USER CODE BEGIN PV */
static uint8_t rx1;
static volatile uint8_t send_on = 1;
static const uint8_t msg[] = "hello windows!\r\n";
/* USER CODE END PV */

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART1_UART_Init();

  // 开启一次性中断接收（很重要）
  HAL_UART_Receive_IT(&huart1, &rx1, 1);

  while (1)
  {
    if (send_on)
    {
      HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen((char*)msg), HAL_MAX_DELAY);
      HAL_Delay(500); // 带延时版本：不丢包；去掉延时用于观察丢包现象
    }
  }
}

/**
  * @brief  串口接收完成回调（HAL 自动调用）
  */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART1)
  {
    switch (rx1)
    {
      case '#': send_on = 0; break; // 暂停发送
      case '*': send_on = 1; break; // 继续发送
      default: break;               // 忽略其它字符（比如 \r \n）
    }
    // 关键：再次启动下一次接收（HAL 的中断接收是“单次”的）
    HAL_UART_Receive_IT(&huart1, &rx1, 1);
  }
}
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /* 使能电源&AFIO时钟（部分库版本不需要 AFIO 可省略） */
  __HAL_RCC_AFIO_CLK_ENABLE();

  /* 配置振荡器：HSE=ON, PLL 源=HSE, PLL= x9 => 8MHz * 9 = 72MHz */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState       = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState       = RCC_HSI_ON;       // 备选保留
  RCC_OscInitStruct.PLL.PLLState   = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource  = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL     = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /* 初始化总线时钟：SYSCLK=72MHz, HCLK=72MHz, APB1=36MHz, APB2=72MHz */
  RCC_ClkInitStruct.ClockType      = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                                   | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource   = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider  = RCC_SYSCLK_DIV1;    // HCLK=72
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;      // PCLK1=36
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;      // PCLK2=72
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }

  /* SysTick 由 HAL_Init() 统一配置；若需要可在此处补充时基 */
}

void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {
    /* 可在此处加上 LED 闪烁/断言等 */
  }
}
/* ==== END ==== */