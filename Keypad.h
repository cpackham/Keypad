/*
    Keypad.h - Library for handling the keypad on a LCD1602

    The keypad is connected via and analog pin via a 5 stage voltage divider
    (meaning that each button corresponds to a different voltage level on the
    same input). This is usually A0 but check the datasheet.

    Copyright (c) 2015 Chris Packham

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef Keypad_h
#define Keypad_h

#include <Arduino.h>

typedef enum
{
  KEY_NONE = 0,
  KEY_RIGHT,
  KEY_LEFT,
  KEY_UP,
  KEY_DOWN,
  KEY_SELECT
} Key;

class Keypad
{
  public:
    Keypad(int pin);
    Key keyRead(void);
  private:
    int _pin;
};

#endif
