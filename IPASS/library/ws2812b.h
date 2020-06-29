#ifndef WS2812B_HPP
#define WS2812B_HPP

#include <bitset>
#include "hwlib.hpp"

/// @file

/// \brief
/// WS2812B interface
/// \details
/// This class creates an interface for the SAM based Arduino Due.
/// This allows the Due to control the WS2812B LED series.
///
/// Dependencies: std::bitset and hwlib (github.com/wovo/hwlib).
class ws2812b{
private:
    // Pin assigned by the end user to control the WS2812B strip.
    hwlib::target::pins pin;
public:

    /// \brief
    /// Default constructor
    /// \details
    /// Constructor taking a Arduino PWM pin (for example: hwlib::target::pins::d8)
    ws2812b(hwlib::target::pins & pin):
        pin(pin)
    {}

    /// \brief
    /// Update LED pattern
    /// \details
    /// Update WS2812B with new pattern
    /// Function inserts new GRB pattern (Green, Red, Blue), each with 8 bits, times 'amount'.
    /// Word of warning: As of this version, only 0xFF / 255 results in a burning LED.
    void update(const unsigned & amount, const uint_fast8_t & red, const uint_fast8_t & green, const uint_fast8_t & blue);

    /// \brief
    /// Reset code signal
    /// \details
    /// Sends a reset signal to the WS2812B strip
    void reset();
};
#endif //WS2812B_HPP