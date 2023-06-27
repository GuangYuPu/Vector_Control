#include "User_VC_Thread.h"
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Coordinate_Trans.h"
#include "tim.h"
#include "SVPWM.h"


void Task_VC(void *argument)
{
    (void)argument;
    HAL_TIM_Base_Start_IT(&htim1); //开启定时器
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  
  if (htim->Instance == TIM1) {
    Svpwm_t Duty_abc;
    Svpwm_Calculate(&Duty_abc,Ud,Ua_ref,Ub_ref,Uc_ref);
    __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,Duty_abc.ccRA);
    __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,Duty_abc.ccRB);
    __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3,Duty_abc.ccRC);
  }
  
  if (htim->Instance == TIM7) {
    HAL_IncTick();
  }
  
}

void Task_VC_start()
{
    xTaskCreate(Task_VC, "Task_VC", 1024, NULL, 3, NULL);
}



