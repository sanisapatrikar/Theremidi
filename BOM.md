# 📋 Theremidi — Bill of Materials (BOM)

This document provides the complete hardware parts list, component specifications, 3D printing parameters, and fasteners required to build **Theremidi**.

---

## 1. 3D Printable Mechanical Parts

Files located in [`3D Printable Files/`](file:///Users/krishnanh/Projects/Theremidi/3D%20Printable%20Files):

| Part Name | File | Qty | Function / Description | Recommended Print Settings |
| :--- | :--- | :---: | :--- | :--- |
| **Enclosure Base** | [`base.stl`](file:///Users/krishnanh/Projects/Theremidi/3D%20Printable%20Files/base.stl) | **1x** | Main chassis housing the microcontroller, wiring, and breakout connections. | PLA / PETG, 0.2mm layer, 20% infill, no supports needed. |
| **Enclosure Top Lid** | [`lid.stl`](file:///Users/krishnanh/Projects/Theremidi/3D%20Printable%20Files/lid.stl) | **1x** | Top faceplate containing cutouts for dual ultrasonic sensor transducers. | PLA / PETG, 0.2mm layer, 20% infill. |
| **Structural Connector**| [`connector.stl`](file:///Users/krishnanh/Projects/Theremidi/3D%20Printable%20Files/connector.stl) | **2x** | Internal mounting brackets / clips for secure assembly. | PLA / PETG, 0.16–0.2mm layer, 30% infill for added rigidity. |

---

## 2. Hardware Fasteners

| Item | Specification | Qty | Purpose |
| :--- | :--- | :---: | :--- |
| **Machine Screws** | **M3 × 5mm** (Button or socket head) | **4x** | Secures the top lid and internal chassis brackets to the base enclosure. |
| **Rubber Bumpons / Feet** *(Optional)* | 8mm–10mm diameter self-adhesive | 4x | Anti-slip feet for studio desk placement. |

---

## 3. Electronic Components

Theremidi supports two distinct build configurations:

### Configuration A: USB-MIDI Parameter Controller (Recommended Studio Mode)
*Firmware: [`software_version_w_smoothening_algo.ino`](file:///Users/krishnanh/Projects/Theremidi/software_version_w_smoothening_algo.ino)*

| Component | Specification / Model | Qty | Notes |
| :--- | :--- | :---: | :--- |
| **Microcontroller** | **ESP32-S2** or **ESP32-S3** Dev Board | 1x | **Must support native USB** (`USB.h` / `USB-MIDI.h`) for class-compliant MIDI over USB without external drivers. |
| **Ultrasonic Sensors** | **HC-SR04P** (3.3V) or **HC-SR04** (5V) | 2x | Ultrasonic distance measurement (Pitch / CC 16 and Volume / CC 17). |
| **Voltage Dividers** | 1kΩ & 2kΩ resistors (or 3.3V logic shifter) | 2 pairs | Only needed if using standard 5V HC-SR04 to protect ESP32 3.3V Echo GPIOs. |
| **USB Data Cable** | USB-C or Micro-USB (depending on board) | 1x | High-quality data cable for power and MIDI data streaming to PC/Mac/iPad. |
| **Prototyping / Wire** | Half-size solderless breadboard or perfboard | 1x | For compact internal wiring. |
| **Jumper Wires** | 10cm Female-to-Female & Male-to-Female | 10–12x | Connecting sensor pins to GPIO headers. |

---

### Configuration B: Standalone Digital Synthesizer (Direct Audio Mode)
*Firmware: [`theremin_arduino_code.ino`](file:///Users/krishnanh/Projects/Theremidi/theremin_arduino_code.ino) + [`theremin_esp_code.ino`](file:///Users/krishnanh/Projects/Theremidi/theremin_esp_code.ino)*

| Component | Specification / Model | Qty | Notes |
| :--- | :--- | :---: | :--- |
| **Co-Processor** | **Arduino Uno Rev3** (or Nano) | 1x | Reads dual ultrasonic sensors and transmits serial distance pairs over UART. |
| **Synthesizer MCU** | **ESP32 Dev Board** (Classic WROOM-32) | 1x | Runs real-time DDS sine synthesis and outputs audio via 8-bit DAC1 (GPIO 25). |
| **Audio Output** | 3.5mm TRS stereo/mono audio jack | 1x | Audio output to mixer, active monitors, or amp. |
| **Coupling Capacitor**| 10µF electrolytic capacitor | 1x | DC-blocking capacitor placed in series between DAC pin (GPIO 25) and audio jack. |
| **Amplifier** *(Optional)* | PAM8403 3W Stereo Class-D Audio Amp module | 1x | Required only if driving a passive speaker directly. |
| **Speaker** *(Optional)* | 4Ω or 8Ω, 2W–3W mini speaker | 1x | For self-contained portable acoustic playback. |

---

## 4. Tools Required for Assembly
- 2.0mm / 2.5mm Hex driver (for M3 screws)
- Soldering iron and solder (for permanent perfboard builds) or jumper wires (for breadboard builds)
- Wire stripper and flush cutters
- 3D printer with PLA/PETG filament
