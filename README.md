Theremidi: Contactless MIDI Parameter Controller & Digital Instrument

Theremidi is a fusion of the classic Theremin’s gesture-based control and modern MIDI protocols. Developed on the ESP32, it functions as a dual-purpose device: a standalone digital musical instrument and a cost-effective contactless parameter controller for professional music software.

🚀 The Vision:

The project originated from a team design challenge: bridging the gap between traditional expressive instruments and rigid digital MIDI controllers. While commercial contactless controllers often carry a high price tag, Theremidi provides a low-cost, high-precision alternative using ultrasonic sensing and custom smoothing algorithms.

🛠️ Project Versions:
1. Software Mode (Parameter Controller)
In this mode, the device acts as a HID (Human Interface Device) that maps hand proximity to MIDI CC (Continuous Controller) messages.
Control Mapping: Currently mapped to Parameters 16 (Reverb) and 17 (Cutoff), chosen for their continuous nature.
Smoothing Algorithm: Implemented a custom algorithm to eliminate "jitter" from ultrasonic sensors, ensuring professional-grade parameter sweeps.Integration: Validated at technical exhibitions for its seamless integration with software synthesizers and DAWs.
2. Hardware Mode (Standalone Instrument)
The original "Digital Theremin" prototype designed for standalone performance.
Waveform Synthesis: Maps distances to notes across an octave using dacWrite() to generate real-time analog waveforms.
Standalone: Requires only a power source and a speaker; no external plugins or PC required.

🔧 Technical Stack

Microcontroller: ESP32, Arduino Uno (testing)

Sensors: HC-SR04 Ultrasonic Sensors 

Protocols: MIDI over USB, I2C 

Processing: Real-time signal smoothing and amplitude modulation 

🏗️ Future Roadmap

Finalize the hardware prototype into a production-ready standalone unit.
Expand MIDI mapping to support 12+ simultaneous parameters using gesture recognition.
