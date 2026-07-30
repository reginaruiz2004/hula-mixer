# Electronics & Wiring

## Arduino Uno → L298N

| L298N Pin | Arduino Uno Pin |
|---|---|
| ENA | D11 |
| IN1 | D9 |
| IN2 | D8 |
| IN3 | D7 |
| IN4 | D6 |
| ENB | D10 |
| GND | GND (shared rail) |

## L298N → NEMA17 Motor

| Motor Wire | L298N Output |
|---|---|
| Black | OUT1 |
| Blue | OUT2 |
| Green | OUT3 |
| Red | OUT4 |

Coil pairs confirmed via multimeter: Black-Blue (Coil A), Green-Red (Coil B).

⚠️ **Do not assume this matches other NEMA17 units** — coil color conventions vary 
by manufacturer/batch. Always verify with a multimeter before wiring.

## Power switch (3-pin illuminated rocker, SPDT)

| Switch Pin | Connects To |
|---|---|
| Common | +12V supply input |
| Terminal 1 | +12V rail (L298N power + Arduino VIN) |
| Terminal 2 | Not used |
| LED pin | GND rail |

Switch is panel-mounted on the enclosure, wired to the perfboard via cable 
(not soldered directly to the perfboard) so the switch can be accessed externally 
while the perfboard stays hidden inside the case.

## Perfboard layout

- Size: 10x7cm, isolated-hole perfboard
- Arduino Uno and L298N mounted side by side
- Two dedicated rows: +12V rail and GND rail, bridged with soldered jumper wire 
  across all connection points on each row
- All components (Arduino VIN, L298N power, switch output) tap into these two rails

## Reference wiring diagram

Built in Tinkercad Circuits (L293D component used as L298N stand-in, since 
Tinkercad's library does not include the L298N specifically).

![Tinkercad wiring diagram](images/wiring-diagram-tinkercad.png)

## Test code

See [`firmware/hula_mixer.ino`](../firmware/hula_mixer.ino) for the motor test sketch 
(single-direction rotation, used to validate wiring before full implementation).