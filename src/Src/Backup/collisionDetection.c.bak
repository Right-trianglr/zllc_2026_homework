//
// Created by Right on 2025/11/11.
//

#include "collisionDetection.h"
#include "main.h"

extern TIM_HandleTypeDef htim1;
static int numDetected = 0;

void startCollisionDetection(void) {
    HAL_TIM_Base_Start_IT(&htim1);
}

void handleDetection(void) {
    GPIO_PinState state = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1);
    if (state == GPIO_PIN_SET) {
        numDetected++;
    }
    if (numDetected>=10) {
        numDetected = 0;
    }
}