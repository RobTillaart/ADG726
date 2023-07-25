
[![Arduino CI](https://github.com/RobTillaart/ADG726/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/ADG726/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/ADG726/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/ADG726/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/ADG726/actions/workflows/jsoncheck.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/ADG726/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/ADG726.svg?maxAge=3600)](https://github.com/RobTillaart/ADG726/releases)


# ADG726

Arduino library for ADG726 - 16 to 1 channel (2x) multiplexer.


## Description

**Experimental**

ADG726 is an Arduino class that controls two 16 to 1 multiplexers
over a parallel interface.
Only one of the 16 channels can be connected at the same time.
The channels can be set per multiplexer or together in one call.
The library also support to set them all off (17th state).

On power-up, all switches are in the OFF state.

This library can be used e.g. to connect 16 analog devices to
one analog port, or to select between 16 DHT22 sensors.

No tests with hardware have been done yet, so use with care.
Feedback welcome!


TODO insert picture.


#### Related

- https://github.com/RobTillaart/HC4051 (1x8 mux)
- https://github.com/RobTillaart/HC4052 (2x8 mux)
- https://github.com/RobTillaart/HC4053 (3x2 mux)
- https://github.com/RobTillaart/HC4067 (1x16 mux)
- https://github.com/RobTillaart/ADG725 (2x16 mux)
- https://github.com/RobTillaart/ADG726 (2x16 mux)
- https://github.com/RobTillaart/ADG731 (1x32 mux)
- https://github.com/RobTillaart/ADG732 (1x32 mux)


## Interface

```cpp
#include "ADG726.h"
```

- **ADG726(uint8_t A0, uint8_t A1, uint8_t A2, uint8_t A3, uint8_t CSA, uint8_t CSB, uint8_t EN, uint8_t WR)** constructor.
- **ADG726(uint8_t address[4], uint8_t CSA, uint8_t CSB, uint8_t EN, uint8_t WR)** constructor.
- **void setChannel(uint8_t channel)** set the current channel for both A and B.
Valid values for channel are 0..15.
- **void setChannelA(uint8_t channel)** set the current channel for A only.
Valid values for channel are 0..15.
- **void setChannelB(uint8_t channel)** set the current channel for B only.
Valid values for channel are 0..15.
- **uint8_t getChannelA()** get last set channel A == 0..15 or ADG726_ALLOFF.
- **uint8_t getChannelB()** get last set channel B == 0..15 or ADG726_ALLOFF.
- **uint8_t channelCount()** returns 16 for ADG726.
- **void allOff()** sets all channels to OFF, none selected.


## Future

#### Must

- improve documentation
- test with hardware
- keep in sync with ADG725 (interface)

#### Should

- add examples
- check performance

#### Could


#### Wont


