#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "tim.h"

#include "User_VC.h"

//初始化与采样数据处理线程
void Task_VC(void *argument)
{
    (void)argument;
    #define VC_TASK_ENABLE
    HAL_TIM_Base_Start_IT(&htim1); //开启定时器
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);
    User_VC_init();
}

//SVPWM占空比调整线程
void Task_Vc_Loop(TIM_HandleTypeDef *htim)
{
  #ifdef VC_TASK_ENABLE
  if (htim->Instance == TIM1) {
    //采样数据处理
    Sample_Refesh(&Sample_i,&Sample_u,ia,ib,ic);
    
    //锁相
    PLL_SinglePhase(&amplitude_pll,&theta_pll,Sample_i.abc_value.a,theta_pll);
    #ifdef PLL_ENABLE
      theta_ref = theta_pll;
    #endif

    //伺服
    CurrentServo(&hVC,Id_Servo,Iq_Servo,theta_ref);

    //SVPWM输出
    Svpwm_t Duty_abc;
    Svpwm_Calculate(&Duty_abc,Ud,Ua_ref,Ub_ref,Uc_ref);
    __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,Duty_abc.ccRA);
    __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,Duty_abc.ccRB);
    __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3,Duty_abc.ccRC);
  }
  #endif
}

void Task_VC_start()
{
    xTaskCreate(Task_VC, "Task_VC", 512, NULL, 3, NULL);
}



