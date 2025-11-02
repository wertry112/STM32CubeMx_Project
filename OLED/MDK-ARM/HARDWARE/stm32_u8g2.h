#ifndef __STM32_U8G2_H
#define __STM32_U8G2_H

#include "u8g2.h"
#include "u8x8.h"
#include "stm32f1xx_hal.h"

extern u8g2_t u8g2;

// HAL I2C 回调
uint8_t u8x8_byte_stm32hal_i2c(u8x8_t* u8x8, uint8_t msg, uint8_t arg_int, void* arg_ptr);
uint8_t u8x8_gpio_and_delay_stm32(u8x8_t* u8x8, uint8_t msg, uint8_t arg_int, void* arg_ptr);

// OLED 初始化
void OLED_Init(void);

// 显示字符串
void OLED_ShowString(uint8_t x, uint8_t y, const char* str);

// 左右滑动文字
void OLED_ShowStringScroll(const char* str, uint8_t y);

// 显示图案
void OLED_ShowBitmap(const uint8_t* bitmap, uint8_t w, uint8_t h, uint8_t x, uint8_t y);

#endif
