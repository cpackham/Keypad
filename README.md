# Keypad - Library for the keypad on a LCD1602

The keypad is connected via and analog pin via a 5 stage voltage divider
(meaning that each button corresponds to a different voltage level on the same
input). This is usually A0 but check the datasheet.

This library doesn't do any debouncing for you (although the voltage ranges
for the keys are fairly restrictive). Any ratelimiting or debouncing is left
to the application.

## Usage

```
#include <Keypad.h>

Keypad keypad(A0)

void setup()
{
}

void loop()
{
  Key k = keypad.keyRead()

  switch (k) {
  case KEY_UP:
    // handle up key
    break;
  ...
  }

  delay(100);
}
```
