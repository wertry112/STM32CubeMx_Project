#include "main.h"
#include "stm32_u8g2.h"
#include "test.h"

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_I2C2_Init();

    OLED_Init();

    // 学号和名字显示
    OLED_ShowString(0, 12, "ID: 632307030513");
    HAL_Delay(1000);
    OLED_ShowString(0, 32, "Name: Jing Haofu");
    HAL_Delay(1000);

    // 左右滑动显示学号
    while(1)
    {
        OLED_ShowStringScroll("ID: 632307030513", 12);
        OLED_ShowStringScroll("Name: Jing Haofu", 32);

        // 小图案动画
        for(int i=0; i<10; i++)
        {
            OLED_ShowBitmap(face_bitmap, 16, 16, i*10, 48);
            HAL_Delay(100);
        }
    }
}
