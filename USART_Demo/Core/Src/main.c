#include "main.h"
#include "string.h"

UART_HandleTypeDef huart1;
uint8_t txData[] = "hello windows!\r\n";
uint8_t rxData;
uint8_t sendFlag = 1;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART1_UART_Init();

  // 启用中断接收
  HAL_UART_Receive_IT(&huart1, &rxData, 1);

  while (1)
  {
    if (sendFlag)
    {
      HAL_UART_Transmit(&huart1, txData, strlen((char*)txData), HAL_MAX_DELAY);
      HAL_Delay(500);
    }
  }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART1)
  {
    switch (rxData)
    {
      case '#': sendFlag = 0; break;
      case '*': sendFlag = 1; break;
      default: break;
    }
    HAL_UART_Receive_IT(&huart1, &rxData, 1);
  }
}
