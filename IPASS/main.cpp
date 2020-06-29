#include "hwlib.hpp"
#include "library/ws2812b.h"

int main(){
    //Amount of LEDs
    uint_fast8_t level1 = 16;
    uint_fast8_t level2 = 32;
    uint_fast8_t level3 = 48;
    uint_fast8_t level4 = 64;

    //8-bit RGB values
    uint_fast8_t red = 0x00;
    uint_fast8_t green = 0x00;
    uint_fast8_t blue = 0x00;

    //Light dependent resistor's values
    uint_fast32_t ldrEntrance = 0;
    uint_fast32_t ldrExit = 0;

    //Pins assigned to LDRs
    auto ldr1 = due::pin_adc(due::ad_pins::a0);
    auto ldr2 = due::pin_adc(due::ad_pins::a1);

    //Pin assigned to WS2812B strip
    auto ledPin = hwlib::target::pins::d8;

    //Instance of WS2812B class
    auto wsb = ws2812b(ledPin);

    //Amount of customers in store
    int customerCount = 0;
    
    while(1){
        ldrEntrance = ldr1.read();
        ldrExit = ldr2.read();
        ldr1.refresh();

        if(ldrEntrance < 100){
            customerCount+=1;
        }
        if(ldrExit < 100){
            customerCount-=1;
        }
        if(customerCount < 0){
            customerCount = 0;
        }
        wsb.reset();
        switch (customerCount){
        case 0:
            //No customers, show black, no leds
            red = 0x00;
            green = 0x00;
            blue = 0x00;
            wsb.update(level4,red,green,blue);
            break;
        case 1:
            //1 customer, show green, 1/4 leds
            red = 0x00;
            green = 0xFF;
            blue = 0x00;
            wsb.update(level1,red,green,blue);
            break;
        case 2:
            //2 customers, show green, 1/4 leds
            red = 0x00;
            green = 0xFF;
            blue = 0x00;
            wsb.update(level1,red,green,blue);
            break;
        case 3:
            //3 customers, show green, 2/4
            red = 0x00;
            green = 0xFF;
            blue = 0x00;
            wsb.update(level2,red,green,blue);
            break;
        case 4:
            //4 customers, show green, 2/4 leds
            red = 0x00;
            green = 0xFF;
            blue = 0x00;
            wsb.update(level2,red,green,blue);
            break;
        case 5:
            //5 customers, show yellow, 3/4 leds
            red = 0xFF;
            green = 0xFF;
            blue = 0x00;
            wsb.update(level3,red,green,blue);
            break;
        case 6:
            //6 customers, show yellow, 3/4 leds
            red = 0xFF;
            green = 0xFF;
            blue = 0x00;
            wsb.update(level3,red,green,blue);
            break;
        case 7:
            //7 customers, show yellow, all leds
            red = 0xFF;
            green = 0xFF;
            blue = 0x00;
            wsb.update(level4,red,green,blue);
            break;
        case 8:
            //8 customers, show red, all leds
            red = 0xFF;
            green = 0x00;
            blue = 0x00;
            wsb.update(level4,red,green,blue);
            break;
        default:
            //Above 8 customers, show bright white, all leds
            red = 0xFF;
            green = 0xFF;
            blue = 0xFF;
            wsb.update(level4,red,green,blue);
            break;
        }
        hwlib::wait_ms(1000);
    }
}