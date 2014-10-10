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
	  LED2_Neg();
	  break;
	default:
	  break;
	}
}

static void APP_Loop(void) {
  for(;;) {
#if PL_HAS_EVENTS
    EVNT_HandleEvent(APP_EventHandler);
#endif
    EVNT_SetEvent(EVNT_INIT); /* set initial event */
  }
}

void APP_Start(void) {
  PL_Init(); /* platform initialization */
  EVNT_SetEvent(EVENT_LED_HEARTBEAT); /* set LED Heartbeat event */
  APP_Loop();
#if 0
  for(;;) {
    LED1_On();
    WAIT1_Waitms(300);
    LED1_Off();
    LED2_On();
    WAIT1_Waitms(300);
    LED2_Off();
    LED3_On();
    WAIT1_Waitms(300);
    LED3_Off();
  }
#endif
  /* just in case we leave the main application loop */
  PL_Deinit();
}
