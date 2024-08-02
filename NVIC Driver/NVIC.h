/*******************************************************************************
 AUTHOR : Uosef Mohsen
 Linkedin: https://www.linkedin.com/in/uosef-mohsen-26468b204/
 GitHub: https://github.com/UosefMohsen
 *******************************************************************************/
#ifndef NVIC_H_
#define NVIC_H_

/*******************************************************************************
 *                                Inclusions                                   *
 *******************************************************************************/
#include "std_types.h"
#include "tm4c123gh6pm_registers.h"

/* Enable Exceptions ... This Macro enable IRQ interrupts, Programmable Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Enable_Exceptions()    __asm(" CPSIE I ")

/* Disable Exceptions ... This Macro disable IRQ interrupts, Programmable Systems Exceptions and Faults by setting the I-bit in the PRIMASK. */
#define Disable_Exceptions()   __asm(" CPSID I ")

/* Enable Faults ... This Macro enable Faults by clearing the F-bit in the FAULTMASK */
#define Enable_Faults()        __asm(" CPSIE F ")

/* Disable Faults ... This Macro disable Faults by setting the F-bit in the FAULTMASK */
#define Disable_Faults()       __asm(" CPSID F ")

/*******************************************************************************
 *                           Data Types Declarations                           *
 *******************************************************************************/
typedef uint8 NVIC_IRQType;
typedef uint8 NVIC_IRQPriorityType;

typedef enum
{
    EXCEPTION_RESET_TYPE,
    EXCEPTION_NMI_TYPE,
    EXCEPTION_HARD_FAULT_TYPE,
    EXCEPTION_MEM_FAULT_TYPE,
    EXCEPTION_BUS_FAULT_TYPE,
    EXCEPTION_USAGE_FAULT_TYPE,
    EXCEPTION_SVC_TYPE,
    EXCEPTION_DEBUG_MONITOR_TYPE,
    EXCEPTION_PEND_SV_TYPE,
    EXCEPTION_SYSTICK_TYPE
}NVIC_ExceptionType;

typedef uint8 NVIC_ExceptionPriorityType;

/************************************************************************************
 *                           Functions Declarations                                *
 ************************************************************************************/
void NVIC_EnableIRQ(NVIC_IRQType IRQ_Num);
void NVIC_DisableIRQ(NVIC_IRQType IRQ_Num);
void NVIC_SetPriorityIRQ(NVIC_IRQType IRQ_Num, NVIC_IRQPriorityType IRQ_Priority);

void NVIC_EnableException(NVIC_ExceptionType Exception_Num);
void NVIC_DisableException(NVIC_ExceptionType Exception_Num);
void NVIC_SetPriorityException(NVIC_ExceptionType Exception_Num, NVIC_ExceptionPriorityType Exception_Priority);

#endif /* NVIC_H_ */
