//
// Created by Right on 2025/10/30.
//
#include "beeper.h"
#include "main.h"

extern TIM_HandleTypeDef htim3;
extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;

/**
 * @brief 启动电池电压监测定时器
 * 定时器定时触发中断，利用adc监测电压
 */
void startBatteryMonitor(void) {
    HAL_ADCEx_Calibration_Start(&hadc1);
    HAL_TIM_Base_Start_IT(&htim3);
}

/**
 * @brief 函数
 * 先使用adc1读取vref用于校准adc
 * 再使用adc2读取并计算电池电压
 * 若电压异常，启动蜂鸣器报警
 */
void handleBatteryMonitor(void) {

    uint16_t ADC_value_battery = 0;
    uint16_t ADC_value_vref = 0;
    float Battery_voltage = 0;
    float Vref = 0;

    // Read ref voltage
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 1);
    ADC_value_vref = HAL_ADC_GetValue(&hadc1);
    Vref = 1.2 * 4095 / ADC_value_vref;
    HAL_ADC_Stop(&hadc1);

    // Read battery voltage
    HAL_ADC_Start(&hadc2);
    HAL_ADC_PollForConversion(&hadc2, 1);
    ADC_value_battery = HAL_ADC_GetValue(&hadc2);
    Battery_voltage = ADC_value_battery * 2 * Vref / 4095.0f;
    HAL_ADC_Stop(&hadc2);

    // battery voltage compare
    // there is no battery when vbat <= 1v
    if ( (Battery_voltage > 1) && (Battery_voltage < 3.5f || Battery_voltage > 4.4f) ) {
        beeperOn();
    }
    else {
        beeperOff();
    }
}