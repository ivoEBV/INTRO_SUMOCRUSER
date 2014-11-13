/**
 * \file
 * \brief Main Application Module.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This module is the main application module. 
 * From here the application runs and performs all tasks.
 */

#include "Platform.h"
#include "Application.h"
#include "WAIT1.h"
#if PL_HAS_LED
  #include "LED.h"
#endif
#if PL_HAS_EVENTS
  #include "Event.h"
#endif
#if PL_HAS_MEALY
  #include "Mealy.h"
#endif
#if PL_HAS_KEYS
  #include "Keys.h"
#endif
#if PL_HAS_SHELL
  #include "Shell.h"
#endif
#if PL_HAS_BUZZER
  #include "Buzzer.h"
#endif
#if PL_HAS_RTOS
  #include "RTOS.h"
  #include "FRTOS1.h"
#endif
#include "Test.h"

static uint8_t lastKeyPressed;

static void APP_EventHandler(EVNT_Handle event) {
  switch(event) {
    case EVNT_INIT:
      LED1_On();
      WAIT1_Waitms(50);
      LED1_Off();
      LED2_On();
      WAIT1_Waitms(50);
      LED2_Off();
      LED3_On();
      WAIT1_Waitms(50);
      LED3_Off();
      break;
    case EVENT_LED_HEARTBEAT:
      LED1_Neg();
      break;
#if PL_NOF_KEYS >= 1
    case EVNT_SW1_PRESSED:
      lastKeyPressed = 1;
  #if PL_HAS_SHELL
      SHELL_SendString("SW1 pressed!\r\n");
  #endif
  #if PL_HAS_BUZZER
      BUZ_Beep(300, 500);
  #endif
      break;
    case EVNT_SW1_LPRESSED:
  #if PL_HAS_SHELL
      SHELL_SendString("SW1 long pressed!\r\n");
  #endif
      break;
    case EVNT_SW1_RELEASED:
  #if PL_HAS_SHELL
      SHELL_SendString("SW1 released!\r\n");
  #endif
      break;
#endif
#if PL_NOF_KEYS >= 2
    case EVNT_SW2_PRESSED:
      lastKeyPressed = 2;
#if PL_HAS_SHELL
      SHELL_SendString("SW2 pressed!\r\n");
#endif
      break;
#endif
#if PL_NOF_KEYS >= 3
    case EVNT_SW3_PRESSED:
      lastKeyPressed = 3;
#if PL_HAS_SHELL
      SHELL_SendString("SW3 pressed!\r\n");
#endif
      break;
#endif
#if PL_NOF_KEYS >= 4
    case EVNT_SW4_PRESSED:
      lastKeyPressed = 4;
#if PL_HAS_SHELL
      SHELL_SendString("SW4 pressed!\r\n");
#endif
      break;
#endif
#if PL_NOF_KEYS >= 5
    case EVNT_SW5_PRESSED:
      lastKeyPressed = 5;
#if PL_HAS_SHELL
      SHELL_SendString("SW5 pressed!\r\n");
#endif
      break;
#endif
#if PL_NOF_KEYS >= 6
    case EVNT_SW6_PRESSED:
      lastKeyPressed = 6;
#if PL_HAS_SHELL
      SHELL_SendString("SW6 pressed!\r\n");
#endif
      break;
#endif
#if PL_NOF_KEYS >= 7
    case EVNT_SW7_PRESSED:
      lastKeyPressed = 7;
#if PL_HAS_SHELL
      SHELL_SendString("SW7 pressed!\r\n");
#endif
      break;
#endif
    default:
      break;
  }
}

#if PL_HAS_RTOS
static void AppTask(void *pvParameters) {
  (void)pvParameters; /* not used */
#if PL_HAS_SHELL
  //CLS1_SendStr("Hello World!\r\n", CLS1_GetStdio()->stdOut);
#endif
  for(;;) {
#if PL_HAS_EVENTS
    EVNT_HandleEvent(APP_EventHandler); /* handle pending events */
#endif
#if PL_HAS_KEYS && PL_NOF_KEYS>0
    KEY_Scan(); /* scan keys */
#endif
#if PL_HAS_MEALY
    MEALY_Step();
#endif
    FRTOS1_vTaskDelay(100/portTICK_RATE_MS);
  }
}
#else
static void APP_Loop(void) {
  int i;

#if PL_HAS_SHELL
  CLS1_SendStr("Hello World!\r\n", CLS1_GetStdio()->stdOut);
#endif
  for(;;) {
#if PL_HAS_EVENTS
    EVNT_HandleEvent(APP_EventHandler); /* handle pending events */
#endif
#if PL_HAS_KEYS && PL_NOF_KEYS>0
    KEY_Scan(); /* scan keys */
#endif
#if PL_HAS_MEALY
    MEALY_Step();
#endif
    WAIT1_Waitms(100);
  }
}
#endif

void APP_Start(void) {
  PL_Init(); /* platform initialization */
  //TEST_Test();
  EVNT_SetEvent(EVNT_INIT); /* set initial event */
#if PL_HAS_RTOS
  if (FRTOS1_xTaskCreate(AppTask, (signed portCHAR *)"App", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
    for(;;){} /* error */
  }
  RTOS_Run();
#else
  APP_Loop();
#endif
#if 0
  for(;;) {
#if PL_HAS_MEALY
    MEALY_Step();
#else
    LED1_On();
    WAIT1_Waitms(300);
    LED1_Off();
    LED2_On();
    WAIT1_Waitms(300);
    LED2_Off();
    LED3_On();
    WAIT1_Waitms(300);
    LED3_Off();
#endif
  }
#endif
  /* just in case we leave the main application loop */
  PL_Deinit();
}
