/**
 * \file
 * \brief Real Time Operating System (RTOS) main program.
 * \author Erich Styger, erich.styger@hslu.ch
 */

#include "Platform.h"
#if PL_HAS_RTOS
#include "RTOS.h"
#include "FRTOS1.h"
#include "LED.h"

#if 0
static portTASK_FUNCTION(Task1, pvParameters) {
  for(;;) {
    LED3_Neg();
    FRTOS1_vTaskDelay(1000/portTICK_RATE_MS)
  }
}

static portTASK_FUNCTION(Task2, pvParameters) {
  for(;;) {
    LED2_Neg();
    FRTOS1_vTaskDelay(1500/portTICK_RATE_MS)
  }
}
#endif

void RTOS_Run(void) {
  FRTOS1_vTaskStartScheduler();
  /* does usually not return here */
}

void RTOS_Init(void) {
  /*! \todo Add tasks here */
#if 0
  if (FRTOS1_xTaskCreate(Task1, (signed portCHAR *)"Task1", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
    for(;;){} /* error */
  }

/*  if (FRTOS1_xTaskCreate(Task2, (signed portCHAR *)"Task2", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
    for(;;){}  error
  }*/
#endif
}

void RTOS_Deinit(void) {
}

#endif /* PL_HAS_RTOS */
