#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "driverlib/uart.c"
#include "driverlib/pin_map.h"
#include "driverlib/timer.h"
#include "driverlib/timer.c"
#include "driverlib/interrupt.h"
#include "lcd.h"
#include "driverlib/adc.h"
#include "driverlib/adc.c"
#include "inc/tm4c123gh6pm.h"

//void timerIntSet(void);
void saatiGonder(void);
void timer0Int(void);
void uart_ayari();
void diger_ayar();
void serikesme();
void adcayar();

int saniye_birler;
int saniye_onlar;
int dakika_birler;
int dakika_onlar;
int saat_birler;
int saat_onlar;
int receivedData = 0;
int adcveri[4];


char receivedClock[8];
char saatVerileri[9];
char av_temperature[3];


void main(){
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
    LCD_init();
//    timerIntSet();
    IntMasterEnable();
    uart_ayari();
    diger_ayar();
    adcayar();

    while(1){
//        saatiGonder();

    }

}

void diger_ayar(){
    IntEnable(INT_UART0);
    UARTIntEnable(UART0_BASE, UART_INT_RX|UART_INT_RT);
    UARTIntClear(UART0_BASE, UART_INT_RX|UART_INT_RT);
    UARTIntRegister(UART0_BASE, serikesme);

}

void uart_ayari(){
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

    // pin ayarları
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    // UART0 yapılandır
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200, // Baud rate: 115200
                        (UART_CONFIG_WLEN_8 |               // 8-bit veri uzunluğu
                         UART_CONFIG_STOP_ONE |             // 1 stop biti
                         UART_CONFIG_PAR_NONE));

}

void serikesme(){
    char c= UARTCharGet(UART0_BASE);

    if (receivedData < 8) //8-1 ilk eleman 0.eleman old için taşma önleniyor.
    {
        receivedClock[receivedData++]=c;
    }

    saniye_birler=receivedClock[7]-'0';
    saniye_onlar=receivedClock[6]-'0';
    dakika_birler=receivedClock[4]-'0';
    dakika_onlar=receivedClock[3]-'0';
    saat_birler=receivedClock[1]-'0';
    saat_onlar=receivedClock[0]-'0';
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);

    TimerConfigure(TIMER0_BASE, TIMER_CFG_A_PERIODIC);
    TimerLoadSet(TIMER0_BASE, TIMER_A, SysCtlClockGet()-1);
    TimerEnable(TIMER0_BASE, TIMER_A);

    IntMasterEnable();
    IntEnable(INT_TIMER0A);

    TimerIntEnable(TIMER0_BASE,TIMER_TIMA_TIMEOUT);
    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    TimerIntRegister(TIMER0_BASE, TIMER_A, timer0Int);

}
//void timerIntSet(void)
//{
//    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
//
//    TimerConfigure(TIMER0_BASE, TIMER_CFG_A_PERIODIC);
//    TimerLoadSet(TIMER0_BASE, TIMER_A, SysCtlClockGet()-1);
//    TimerEnable(TIMER0_BASE, TIMER_A);
//
//    IntMasterEnable();
//    IntEnable(INT_TIMER0A);
//
//    TimerIntEnable(TIMER0_BASE,TIMER_TIMA_TIMEOUT);
//    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
//    TimerIntRegister(TIMER0_BASE, TIMER_A, timer0Int);
//
//}
void timer0Int(void)
{

    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);

    ADCProcessorTrigger(ADC0_BASE, 1);

    while(ADCIntStatus(ADC0_BASE, 1, false) == 0){
           // adcıntstatus ne yapar ?
           //eğer adc0'ın sequence birinden bir gelirse adcıntstatus 1 olur ve adc çevrim işlemini bitirmiş olur.
           //örnek alma işlemi bitince adcıntstatus birleniyor.
           //o zaman bu döngü şu işe yarar, adc örnek alana kadar burada döner ve bekleriz.
       }

    ADCSequenceDataGet(ADC0_BASE, 1, adcveri);

    int ortalamadeger = (adcveri[0] + adcveri[1] + adcveri[2] + adcveri[3]) / 4 ;

    int temp = (1475-((2475*ortalamadeger)/4096)) / 10;

    int temp_onlar = temp / 10;
    int temp_birler = temp % 10;


    if(saniye_birler>=0)
    {
        LCD_Cursor(2, 12);
        LCD_Karakter('0'+temp_birler);

        LCD_Cursor(2, 11);
        LCD_Karakter('0'+temp_onlar);

        LCD_Cursor(1, 12);
        LCD_Karakter('0'+saniye_birler);

        LCD_Cursor(1, 11);
        LCD_Karakter('0'+saniye_onlar);

        LCD_Cursor(1, 10);
        LCD_Karakter(':');

        LCD_Cursor(1, 9);
        LCD_Karakter('0'+dakika_birler);

        LCD_Cursor(1, 8);
        LCD_Karakter('0'+dakika_onlar);

        LCD_Cursor(1, 7);
        LCD_Karakter(':');

        LCD_Cursor(1, 6);
        LCD_Karakter('0'+saat_birler);

        LCD_Cursor(1, 5);
        LCD_Karakter('0'+saat_onlar);

        saniye_birler++;
    }
        if(saniye_birler > 9)
    {
        saniye_birler=0;
        saniye_onlar++;
    }

    if (saniye_onlar > 5)
    {
        saniye_onlar=0;
        dakika_birler++;
    }
    if (dakika_birler > 9)
        {
            dakika_birler=0;
            dakika_onlar++;
        }
    if (dakika_onlar > 5)
        {
            dakika_onlar=0;
            saat_birler++;
        }
    if(saat_birler > 4)
        {
            saat_birler=0;
            saat_onlar++;
        }
    if(saat_onlar==2 & saat_birler==4)
        {
            saat_birler=0;
            saat_onlar=0;
        }

    char saatVerileri[9] = {'0'+saat_onlar, '0'+saat_birler, ':', '0'+dakika_onlar, '0'+dakika_birler, ':', '0'+saniye_onlar,
                            '0'+saniye_birler, '*'};
    int i;
    for( i=0; i<9; i++)
    {
        UARTCharPut(UART0_BASE, saatVerileri[i]);
    }

    char av_temperature[3] = {'0'+temp_onlar ,  '0'+temp_birler , '#'};
    int k;
    for(k=0; k<3; k++)
    {
        UARTCharPut(UART0_BASE, av_temperature[3]);
    }

}
void adcayar()
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); // Çevre birimlerini aktif hale geçirdik, apisiz koddaki bu kodun

    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0); //ADC ENERJİLENDİRİLDİ


    ADCSequenceConfigure(ADC0_BASE, 1, ADC_TRIGGER_PROCESSOR, 0); // ADC0 kullanıldı ve sequence 1 seçildi

    ADCSequenceStepConfigure(ADC0_BASE, 1, 0, ADC_CTL_TS); //Kanal olmadığından daimi sıcaklık sensörünü okuyup ilgili sequence step'ine yazıyor
    ADCSequenceStepConfigure(ADC0_BASE, 1, 1, ADC_CTL_TS);
    ADCSequenceStepConfigure(ADC0_BASE, 1, 2, ADC_CTL_TS);
    ADCSequenceStepConfigure(ADC0_BASE, 1, 3, ADC_CTL_TS|ADC_CTL_IE|ADC_CTL_END);

    ADCSequenceEnable(ADC0_BASE, 1); //ADC Ayarlanması finito

    //henüz adc çalışmaya başlamadı


}


