#include "stm32_u8g2.h"
#include "i2c.h"
#include <string.h>

u8g2_t u8g2;

// I2C 回调
uint8_t u8x8_byte_stm32hal_i2c(u8x8_t* u8x8, uint8_t msg, uint8_t arg_int, void* arg_ptr)
{
    switch(msg)
    {
        case U8X8_MSG_BYTE_INIT:
            break;
        case U8X8_MSG_BYTE_SEND:
            HAL_I2C_Master_Transmit(&hi2c2, u8x8_GetI2CAddress(u8x8), (uint8_t*)arg_ptr, arg_int, 100);
            break;
        case U8X8_MSG_BYTE_START_TRANSFER:
        case U8X8_MSG_BYTE_END_TRANSFER:
            break;
        default: return 0;
    }
    return 1;
}

// GPIO & 延时
uint8_t u8x8_gpio_and_delay_stm32(u8x8_t* u8x8, uint8_t msg, uint8_t arg_int, void* arg_ptr)
{
    switch(msg)
    {
        case U8X8_MSG_DELAY_MILLI:
            HAL_Delay(arg_int);
            break;
        case U8X8_MSG_GPIO_AND_DELAY_INIT:
            break;
        default: break;
    }
    return 1;
}

void OLED_Init(void)
{
    u8g2_Setup_ssd1306_i2c_128x64_noname_f(
        &u8g2,
        U8G2_R0,
        u8x8_byte_stm32hal_i2c,
        u8x8_gpio_and_delay_stm32
    );
    u8g2_InitDisplay(&u8g2);
    u8g2_SetPowerSave(&u8g2, 0);
    u8g2_SetFont(&u8g2, u8g2_font_ncenB08_tr);
}

void OLED_ShowString(uint8_t x, uint8_t y, const char* str)
{
    u8g2_ClearBuffer(&u8g2);
    u8g2_DrawStr(&u8g2, x, y, str);
    u8g2_SendBuffer(&u8g2);
}

void OLED_ShowStringScroll(const char* str, uint8_t y)
{
    int len = strlen(str);
    int width = len * 6; // 估算宽度
    for(int pos=128; pos> -width; pos--)
    {
        u8g2_ClearBuffer(&u8g2);
        u8g2_DrawStr(&u8g2, pos, y, str);
        u8g2_SendBuffer(&u8g2);
        HAL_Delay(50);
    }
}

void OLED_ShowBitmap(const uint8_t* bitmap, uint8_t w, uint8_t h, uint8_t x, uint8_t y)
{
    u8g2_ClearBuffer(&u8g2);
    u8g2_DrawXBMP(&u8g2, x, y, w, h, bitmap);
    u8g2_SendBuffer(&u8g2);
}
