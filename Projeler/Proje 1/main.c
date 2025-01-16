#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_gpio.h"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"

void delayMs(uint32_t delay);

int main(void) {
    // Sistem saatini ve PortF'yi etkinle�tir
    SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    // PortF pinlerini yap�land�r
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);      // PF1 (K�rm�z� LED)
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4); // PF0, PF4 (Switch'ler)
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU); // Pull-up

    while (1) {
        if (GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4) == 0) {  // Switch 1'e bas�ld� (PF4)
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1); // K�rm�z� LED A�
            delayMs(500);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0);         // K�rm�z� LED Kapat
            delayMs(500); // Toplam 1 saniye
        }
        else if (GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0) == 0) { // Switch 2'ye bas�ld� (PF0)
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1); // K�rm�z� LED A�
            delayMs(250);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0);         // K�rm�z� LED Kapat
            delayMs(250); // Toplam 0.5 saniye
        }
        else {
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0); // LED Kapal�
        }
    }
}

void delayMs(uint32_t delay) {
    SysCtlDelay((SysCtlClockGet() / 3000) * delay); // Yakla��k 1 ms
}
