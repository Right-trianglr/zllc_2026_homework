//
// Created by Right on 2025/11/3.
//

#include "colorSwitch.h"
#include "RGB.h"
#include "main.h"

extern TIM_HandleTypeDef htim2;
enum Color_enum ledcolor = red;

void handleColorSwitch() {
    GPIO_PinState state = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);
    switch (state) {
        case GPIO_PIN_RESET:
            ledcolor = blue;
            break;
        case GPIO_PIN_SET:
            ledcolor = red;
            break;
    }
    if (ledcolor == red) {
        RGB_SetColors(8,RED);
        RGB_SendArray(&htim2, TIM_CHANNEL_1);
        RGB_SendArray(&htim2, TIM_CHANNEL_2);
    }
    if (ledcolor == blue) {
        RGB_SetColors(8,BLUE);
        RGB_SendArray(&htim2, TIM_CHANNEL_1);
        RGB_SendArray(&htim2, TIM_CHANNEL_2);
    }
}
