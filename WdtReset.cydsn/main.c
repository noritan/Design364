/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <stdio.h>

int main(void)
{
    uint32 reason;
    char sbuf[64];
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_Start();
    UART_UartPutString("\r\nHELLO WORLD\r\n");
    reason = CySysGetResetReason(CY_SYS_RESET_WDT | CY_SYS_RESET_PROTFAULT | CY_SYS_RESET_SW);
    strcpy(sbuf, "RESET REASON:");
    if (reason & CY_SYS_RESET_WDT) {
        strcat(sbuf, " WDT");
    }
    if (reason & CY_SYS_RESET_PROTFAULT) {
        strcat(sbuf, " FAULT");
    }
    if (reason & CY_SYS_RESET_SW) {
        strcat(sbuf, " SW");
    }
    strcat(sbuf, "\r\n");
    UART_UartPutString(sbuf);

    for(;;)
    {
        /* Place your application code here. */
        if (Pin_SW1_Read()) {
            CySysWdtClearInterrupt();
        }
        CyDelay(100);
    }
}

/* [] END OF FILE */
