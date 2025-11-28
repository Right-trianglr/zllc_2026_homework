//
// Created by Right on 2025/10/30.
//
#include "beeper.h"
#include "main.h"

void beeperOn(void) {
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
}
void beeperOff(void) {
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
}