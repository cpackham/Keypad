/*
    Keypad.cpp - Library for handling the keypad on a LCD1602

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

#include <Arduino.h>
#include <Keypad.h>

#define VRANGE_RIGHT(k)  ((k) < 10)
#define VRANGE_UP(k)     ((k) > 140 && (k) < 150)
#define VRANGE_DOWN(k)   ((k) > 320 && (k) < 365)
#define VRANGE_LEFT(k)   ((k) > 500 && (k) < 510)
#define VRANGE_SELECT(k) ((k) > 740 && (k) < 745)

Keypad::Keypad(int pin)
{
  _pin = pin;
}

Key Keypad::keyRead()
{
  int x = analogRead(_pin);

  if ((x != 1023)) {
    if (VRANGE_SELECT(x)) {
      return KEY_SELECT;
    } else if (VRANGE_LEFT(x)) {
      return KEY_LEFT;
    } else if (VRANGE_RIGHT(x)) {
      return KEY_RIGHT;
    } else if (VRANGE_UP(x)) {
      return KEY_UP;
    } else if (VRANGE_DOWN(x)) {
      return KEY_DOWN;
    }
  }

  return KEY_NONE;
}
