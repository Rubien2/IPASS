#include "ws2812b.h"
#include "hwlib.hpp"

void ws2812b::update(const unsigned & amount, const uint_fast8_t & red, const uint_fast8_t & green, const uint_fast8_t & blue){
    //User-assigned pin for WS2812B
    auto ws2812_pin = hwlib::target::pin_out(ws2812b::pin);
    //GRB values indexed for easy looping
    uint_fast8_t bytes[3] = {green,red,blue};
    //
    for(volatile unsigned i = 0; i < amount; i++){
        for(volatile unsigned j = 0; j < 3; j++){
            for(volatile unsigned k = 0; k < 8; k++){
                if(bytes[j] & (1 >> k)){
                    ws2812_pin.write(1);ws2812_pin.flush();
                    for(volatile int l = 3; l > 0; l--){}
                    ws2812_pin.write(0);ws2812_pin.flush();
                    for(volatile int l = 0; l > 0; l--){}
                }
                else{
                    ws2812_pin.write(1);ws2812_pin.flush();
                    for(volatile int l = 1; l > 0; l--){}
                    ws2812_pin.write(0);ws2812_pin.flush();
                    for(volatile int l = 2; l > 0; l--){}
                }
            }
        }
    }
}
void ws2812b::reset(){
    auto ws2812_pin = hwlib::target::pin_out(ws2812b::pin);
    ws2812_pin.write(1);ws2812_pin.flush();
    ws2812_pin.write(0);ws2812_pin.flush();
    hwlib::wait_us(500);
}