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

void wdt_Callback(void) {
    Pin_LED_Write(!Pin_LED_Read());
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    int_Wdt_StartEx(CySysWdtIsr);
    CySysWdtSetInterruptCallback(wdt_Callback);
    CySysWdtUnmaskInterrupt();

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
