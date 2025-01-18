#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/fpu.h"
#include "math.h"


void fpuExample()
{
    float angleDegrees = 45.0f;
    float angleRadians;
    float sinValue, cosValue, tanValue;


    angleRadians = angleDegrees * (M_PI / 180.0f);


    sinValue = sinf(angleRadians);
    cosValue = cosf(angleRadians);
    tanValue = tanf(angleRadians);


    printf("Açý: %.2f derece\n", angleDegrees);
    printf("Sin: %.4f, Cos: %.4f, Tan: %.4f\n", sinValue, cosValue, tanValue);
}

int main(void)
{

    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);


    FPUEnable();
    FPULazyStackingEnable();


    fpuExample();


    while (1)
    {
    }


}
