/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define Joystick1_X_Pin GPIO_PIN_0
#define Joystick1_X_GPIO_Port GPIOC
#define Joystick1_Y_Pin GPIO_PIN_1
#define Joystick1_Y_GPIO_Port GPIOC
#define Joystick1_Button_Pin GPIO_PIN_2
#define Joystick1_Button_GPIO_Port GPIOC
#define Joystick1_Button_EXTI_IRQn EXTI2_TSC_IRQn
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define Joystick2_X_Pin GPIO_PIN_6
#define Joystick2_X_GPIO_Port GPIOA
#define Joystick2_Y_Pin GPIO_PIN_7
#define Joystick2_Y_GPIO_Port GPIOA
#define SCK_Pin GPIO_PIN_13
#define SCK_GPIO_Port GPIOB
#define DI_Pin GPIO_PIN_15
#define DI_GPIO_Port GPIOB
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define CEE_Pin GPIO_PIN_3
#define CEE_GPIO_Port GPIOB
#define RST_Pin GPIO_PIN_4
#define RST_GPIO_Port GPIOB
#define DC_Pin GPIO_PIN_5
#define DC_GPIO_Port GPIOB
#define Joystick2_Button_Pin GPIO_PIN_6
#define Joystick2_Button_GPIO_Port GPIOB
#define Joystick2_Button_EXTI_IRQn EXTI9_5_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
