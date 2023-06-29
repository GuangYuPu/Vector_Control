#include "User_main.hpp"
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"

#include "User_VC.h"

void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  PLL_init(12,8,50);
  Task_VC_start();
  /* USER CODE END StartDefaultTask */
}
