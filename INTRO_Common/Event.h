/**
 * \file
 * \brief LED driver interface.
 * \author Peter Odermatt, peter.odermatt01@stud.hslu.ch
 *
 * This module implements a generic event driver. We are using numbered events starting with zero.
 * EVNT_HandleEvent() can be used to process the pending events. Note that the event with the number zero
 * has the highest priority and will be handled first
 */

#ifndef EVENT_H_
#define EVENT_H_

#include "Platform.h"

#if PL_HAS_EVENTS

typedef enum EVNT_Handle {
  EVNT_INIT,            /*!< System Initialization Event */
  EVENT_LED_HEARTBEAT,  /*!< Led Heartbeat Event */
#if PL_NOF_KEYS >= 1
  EVNT_SW1_PRESSED,     /*!< SW1 pressed Event */
  EVNT_SW1_LPRESSED,     /*!< SW1 long pressed Event */
  EVNT_SW1_RELEASED,     /*!< SW1 released Event */
#endif
#if PL_NOF_KEYS >= 2
  EVNT_SW2_PRESSED,     /*!< SW2 pressed Event */
  EVNT_SW2_LPRESSED,     /*!< SW2 long pressed Event */
  EVNT_SW2_RELEASED,     /*!< SW2 released Event */
#endif
#if PL_NOF_KEYS >= 3
  EVNT_SW3_PRESSED,     /*!< SW3 pressed Event */
  EVNT_SW3_LPRESSED,     /*!< SW3 long pressed Event */
  EVNT_SW3_RELEASED,     /*!< SW3 released Event */
#endif
#if PL_NOF_KEYS >= 4
  EVNT_SW4_PRESSED,     /*!< SW4 pressed Event */
  EVNT_SW4_LPRESSED,     /*!< SW4 long pressed Event */
  EVNT_SW4_RELEASED,     /*!< SW4 released Event */
#endif
#if PL_NOF_KEYS >= 5
  EVNT_SW5_PRESSED,     /*!< SW5 pressed Event */
  EVNT_SW5_LPRESSED,     /*!< SW5 long pressed Event */
  EVNT_SW5_RELEASED,     /*!< SW5 released Event */
#endif
#if PL_NOF_KEYS >= 6
  EVNT_SW6_PRESSED,     /*!< SW6 pressed Event */
  EVNT_SW6_LPRESSED,     /*!< SW6 long pressed Event */
  EVNT_SW6_RELEASED,     /*!< SW6 released Event */
#endif
#if PL_NOF_KEYS >= 7
  EVNT_SW7_PRESSED,     /*!< SW7 pressed Event */
  EVNT_SW7_LPRESSED,     /*!< SW7 long pressed Event */
  EVNT_SW7_RELEASED,     /*!< SW7 released Event */
#endif
  EVNT_NOF_EVENTS       /*!< Must be last one! */
} EVNT_Handle;

/*!
 * \brief Sets an event.
 * \param[in] event The handle of the event to set.
 */
void EVNT_SetEvent(EVNT_Handle event);

/*!
 * \brief Clears an event.
 * \param[in] event The event handle of the event to clear.
 */
void EVNT_ClearEvent(EVNT_Handle event);

/*!
 * \brief Returns the status of an event.
 * \param[in] event The event handler of the event to check.
 * \return TRUE if the event is set, FALSE otherwise.
 */
bool EVNT_EventIsSet(EVNT_Handle event);

/*!
 * \brief Returns the status of an event. As a side effect, the event gets cleared.
 * \param[in] event The event handler of the event to check.
 * \return TRUE if the event is set, FALSE otherwise.
 */
bool EVNT_EventIsSetAutoClear(EVNT_Handle event);

/*!
 * \brief Routine to check if an event is pending. If an event is pending, the event is cleared and the provided callback is called.
 * \param[in] callback Callback routine to be called. The event handle is passed as argument to the callback.
 */
void EVNT_HandleEvent(void (*callback)(EVNT_Handle));

/*! \brief Event module initialization */
void EVNT_Init(void);

/*! \brief Event module de-initialization */
void EVNT_Deinit(void);

#endif /* PL_HAS_EVENTS */


#endif /* EVENT_H_ */
