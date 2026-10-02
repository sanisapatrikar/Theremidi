# 📋 Theremidi — Bill of Materials (BOM)

This document provides the hardware parts list, component specifications, 3D printing parameters, and fasteners for building the **Theremidi** DIY prototype.

> [!NOTE]
> **DIY Prototype Notice**: Theremidi is an open-source experimental project and proof-of-concept. The components listed below represent our working prototype build. Makers are encouraged to adapt, substitute (e.g., using 3.3V-native ToF sensors or alternative ESP32 dev boards), and customize the design.

---

## 1. 3D Printable Mechanical Parts

Files located in [`hardware/3D Printable Files/`](hardware/3D%20Printable%20Files/):

| Part Name | File | Qty | Function / Description | Recommended Print Settings |
| :--- | :--- | :---: | :--- | :--- |
| **Enclosure Base** | [`base.stl`](hardware/3D%20Printable%20Files/base.stl) | **1x** | Prototype chassis housing the microcontroller, wiring, and breakout connections. | PLA / PETG, 0.2mm layer, 20% infill. |
| **Enclosure Top Lid** | [`lid.stl`](hardware/3D%20Printable%20Files/lid.stl) | **1x** | Top faceplate containing cutouts for dual ultrasonic sensor transducers. | PLA / PETG, 0.2mm layer, 20% infill. |
| **Structural Connector**| [`connector.stl`](hardware/3D%20Printable%20Files/connector.stl) | **2x** | Internal mounting brackets / clips for structural rigidity. | PLA / PETG, 0.2mm layer, 30% infill. |

---

## 2. Hardware Fasteners

| Item | Specification | Qty | Purpose |
| :--- | :--- | :---: | :--- |
| **Machine Screws** | **M3 × 5mm** (Button or socket head) | **4x** | Secures the top lid and internal chassis brackets to the base enclosure. |
| **Rubber Feet** *(Optional)* | 8mm–10mm diameter self-adhesive | 4x | Non-slip feet for desktop stability. |

---

## 3. Electronic Components

Theremidi supports two distinct prototype configurations:

### Configuration A: USB-MIDI Parameter Controller Mode
*Firmware: [`firmware/usb_midi_controller/usb_midi_controller.ino`](firmware/usb_midi_controller/usb_midi_controller.ino)*

| Component | Specification / Model | Qty | Notes |
| :--- | :--- | :---: | :--- |
| **Microcontroller** | **ESP32-S2** or **ESP32-S3** Dev Board | 1x | **Must support native USB** (`USB.h` / `USB-MIDI.h`) for class-compliant MIDI over USB without external bridge software. |
| **Ultrasonic Sensors** | **HC-SR04P** (3.3V) or **HC-SR04** (5V) | 2x | Ultrasonic distance measurement (Pitch / CC 16 and Volume / CC 17). |
| **Voltage Dividers** | 1kΩ & 2kΩ resistors (or 3.3V logic shifter) | 2 pairs | Only needed if using standard 5V HC-SR04 to protect ESP32 3.3V Echo GPIOs. |
| **USB Data Cable** | USB-C or Micro-USB (depending on board) | 1x | Data cable for power and MIDI streaming to PC/Mac/tablet. |
| **Prototyping / Wire** | Half-size solderless breadboard or perfboard | 1x | For compact internal wiring. |
| **Jumper Wires** | 10cm Female-to-Female & Male-to-Female | 10–12x | Connecting sensor pins to GPIO headers. |

---

### Configuration B: Standalone Digital Synthesizer Mode
*Firmware: [`firmware/standalone_sensor_arduino/standalone_sensor_arduino.ino`](firmware/standalone_sensor_arduino/standalone_sensor_arduino.ino) + [`firmware/standalone_synth_esp32/standalone_synth_esp32.ino`](firmware/standalone_synth_esp32/standalone_synth_esp32.ino)*

| Component | Specification / Model | Qty | Notes |
| :--- | :--- | :---: | :--- |
| **Sensor Scanner** | **Arduino Uno Rev3** (or Nano) | 1x | Reads dual ultrasonic sensors and transmits serial distance pairs over UART. |
| **Synthesizer MCU** | **ESP32 Dev Board** (Classic WROOM-32) | 1x | Runs real-time DDS sine synthesis and outputs audio via 8-bit DAC1 (GPIO 25). |
| **Audio Output** | 3.5mm TRS audio jack | 1x | Line-level audio output. |
| **Coupling Capacitor**| 10µF electrolytic capacitor | 1x | DC-blocking capacitor placed in series between DAC pin (GPIO 25) and audio jack. |
| **Amplifier** *(Optional)* | PAM8403 3W Stereo Class-D Audio Amp module | 1x | Required only if driving a passive speaker directly. |
| **Speaker** *(Optional)* | 4Ω or 8Ω, 2W–3W mini speaker | 1x | For standalone acoustic experimentation. |

---

## 4. Assembly & Prototyping Notes
- A 2.0mm / 2.5mm hex driver is needed for M3 screws.
- For testing, a solderless breadboard and Dupont jumper wires are sufficient. For a more rugged build inside the enclosure, perfboard soldering is recommended.
