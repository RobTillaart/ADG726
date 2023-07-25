#pragma once
//
//    FILE: ADG726.h
//  AUTHOR: Rob Tillaart
//    DATE: 2023-07-24
// VERSION: 0.1.0
// PURPOSE: Arduino library for ADG726 - 16 to 1 channel (2x) multiplexer
//     URL: https://github.com/RobTillaart/ADG726


#include "Arduino.h"

#define ADG726_LIB_VERSION         (F("0.1.0"))

#define ADG726_ALLOFF              0x80    //  ENable bit (false)
#define ADG726_A_ONLY              0x20    //  retain B
#define ADG726_B_ONLY              0x40    //  retain A
#define ADG726_AB_BOTH             0x00    //  retain none


class ADG726
{
public:
  ADG726(uint8_t A0, uint8_t A1, uint8_t A2, uint8_t A3, uint8_t CSA, uint8_t CSB, uint8_t EN, uint8_t WR)
  {
    uint8_t ar[4] = { A0, A1, A2, A3 };
    ADG726(arr, CSA, CSB, EN, WR);
  }

  explicit ADG726(uint8_t address[4], uint8_t CSA, uint8_t CSB, uint8_t EN, uint8_t WR)
  {
    for (int i = 0; i < 4; i++)
    {
      _address[i] = address[i];
      pinMode(_address[i], OUTPUT);
      digitalWrite(_address[i], LOW);
    }

    _CSA = CSA;
    _CSB = CSB;
    _EN  = EN;
    _WR  = WR;
    pinMode(_CSA, OUTPUT);
    pinMode(_CSB, OUTPUT);
    pinMode(_EN,  OUTPUT);
    pinMode(_WR,  OUTPUT);

    digitalWrite(_CSA, HIGH);
    digitalWrite(_CSB, HIGH);
    digitalWrite(_EN,  HIGH);
    digitalWrite(_WR,  HIGH);

    //  default all off.
    _channelA = ADG726_ALLOFF;
    _channelB = ADG726_ALLOFF;
  }

  //  set both channels
  void setChannel(uint8_t channel)
  {
    _channelA = channel & 0x0F;
    _channelB = _channelA;
    write(_channelA, LOW, LOW, LOW);
  }

  void setChannelA(uint8_t channel)
  {
    _channelA = channel & 0x0F;
    write(_channelA, LOW, HIGH, LOW);
  }

  void setChannelB(uint8_t channel)
  {
    _channelB = channel & 0x0F;
    write(_channelB, HIGH, LOW, LOW);
  }

  //  last set channel
  uint8_t getChannelA()
  {
    return _channelA;
  }


  uint8_t getChannelB()
  {
    return _channelB;
  }


  uint8_t channelCount()
  {
    return 16;
  }


  void allOff()
  {
    _channelA = ADG726_ALLOFF;
    _channelB = _channelA;
    write(_channelA, LOW, LOW, HIGH);
  }


private:
  void write(uint8_t data, uint8_t csa, uint8_t csb, uint8_t en)
  {
    digitalWrite(_CSA, csa);
    digitalWrite(_CSB, csb);
    digitalWrite(_WR, LOW);

    digitalWrite(_EN, en);
    uint8_t mask = 0x01;
    for (int i = 0; i < 4; i++)
    {
      digitalWrite(_addr[i], ((data & mask) > 0));
      mask <<= 1;
    }
    digitalWrite(_EN, HIGH);

    digitalWrite(_WR, HIGH);
    digitalWrite(_CSB, HIGH);
    digitalWrite(_CSA, HIGH);
  }

  uint8_t  _addr[4];
  uint8_t  _CSA;
  uint8_t  _CSB;
  uint8_t  _EN;
  uint8_t  _WR;
  uint8_t  _channelA;
  uint8_t  _channelB;
};


//  -- END OF FILE --
