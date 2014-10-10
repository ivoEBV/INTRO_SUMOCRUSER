/**
 * \file
 * \brief Main Application Interface.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * Interface to the main application module. 
 * From here the application runs and performs all tasks.
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#if PL_HAS_EVENTS
  #include "Event.h"
#endif

/*!
 *
 * @param event
 */
static void APP_EventHandler(EVNT_Handle event);

/*!
 * \brief Application loop with event handler
 */
static void APP_Loop(void);


/*!
 * \brief Application main start and main routine 
 */
void APP_Start(void);

#endif /* APPLICATION_H_ */
