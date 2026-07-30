# Hula Mixer

Low-cost lab mixer built with Arduino Uno, L298N, and a NEMA17 stepper motor.

## Overview

DIY rotary mixer designed as a cost-effective alternative to commercial lab mixers. Built around an Arduino Uno controlling a NEMA17 stepper motor through an L298N driver, with a rocker switch for power control.

## Status

🔧 In progress — motor control validated, working on perfboard assembly and enclosure design.

## Components

- Arduino Uno R3
- L298N motor driver
- NEMA17 stepper motor (17HS4401)
- Illuminated rocker switch (3-pin, SPDT)
- 12V power supply
- Perfboard (10x7cm)

See [BOM.md](docs/BOM.md) for full parts list.

## Progress Log

- **2026-07-30:** Motor control validated with L298N (coil pairing confirmed: Black-Blue, Green-Red). Wiring diagram completed in Tinkercad. GitHub repo created.

## Documentation

- [Bill of Materials](docs/BOM.md)
- [Design Decisions](docs/DECISIONS.md)
- [Electronics & Wiring](docs/electronics.md)