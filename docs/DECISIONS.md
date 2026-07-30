# Design Decisions

## Driver: L298N over A4988

Chose L298N instead of A4988 (used in Megaruptor) because:
- Mixing does not require microstepping precision — full-step control is sufficient
- Simpler wiring for this use case, no Vref calibration needed
- Already had L298N on hand from initial project attempt

## Arduino: Uno over Nano

Initial attempts used an Arduino Nano, which had persistent unreliability issues — 
traced to counterfeit Nano boards from MercadoLibre containing LGT8F328P chips that 
mimic the ATmega328P bootloader but don't execute code identically. Switched to 
Arduino Uno R3 (Gelek brand) for reliable, consistent behavior.

## Motor coil identification

The NEMA17 motor used in this build has different coil pairing than the one used in 
Megaruptor. Confirmed via multimeter continuity testing:
- **Coil A:** Black - Blue
- **Coil B:** Green - Red

This does NOT match standard color conventions assumed from other NEMA17 units — 
always verify coil pairs with a multimeter before wiring to the driver, rather than 
assuming based on wire color alone.

## Switch wiring (SPDT, 3-pin illuminated rocker)

The switch has 3 terminals: two switching contacts + one LED return pin. Wiring:
- **Common terminal** → +12V power supply input
- **Terminal 1** (switched output) → +12V rail (L298N power + Arduino VIN)
- **Terminal 2** → unused
- **LED pin** → GND rail

Switch is mounted on the enclosure panel (not on the perfboard) and connects to the 
perfboard via cable, to keep the perfboard fully enclosed and hidden.

## Power distribution: shared +12V/GND rails

Perfboard uses two dedicated rows — one for +12V, one for GND — rather than routing 
individual wires from the power source to each component. Simplifies future additions 
(e.g., keypad) by giving them a common power point to tap into.