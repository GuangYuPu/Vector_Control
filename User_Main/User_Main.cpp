#include "User_main.hpp"
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"

#include "User_VC_Thread.h"

void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  Task_VC_start();
  /* USER CODE END StartDefaultTask */
}
