// ESP32 Code using Serial2 on GPIO16 to receive (pitchDist, volumeDist)
// Generates amplitude-modulated sine wave on DAC pin (GPIO25)

const int dacPin = 25;  // DAC1 pin on ESP32
const int RX_PIN = 16;  // Arduino TX → ESP32 RX2 (GPIO16)
const int TX_PIN = 17;  // Not used here, but required to init Serial2

float frequency = 440.0;  // Default frequency
float amplitude = 127.0;  // Default amplitude (0–255 scale)

unsigned long prevMicros = 0;
float wavePhase = 0;
float waveIncrement = 0;

void setup() {
  Serial.begin(115200);           // Debugging to serial monitor
  Serial2.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);  // Data from Arduino

  dacWrite(dacPin, 127);  // Start with neutral DAC value (midpoint)
}

void loop() {
  // Read data from Arduino
  if (Serial2.available()) {
    String data = Serial2.readStringUntil('\n');
    data.trim();

    if (data.length() > 0 && data.indexOf(',') != -1) {
      int commaIndex = data.indexOf(',');
      String pitchStr = data.substring(0, commaIndex);
      String volumeStr = data.substring(commaIndex + 1);

      int pitchDist = pitchStr.toInt();
      int volumeDist = volumeStr.toInt();

      // Debug print
      Serial.print("Received PitchDist: ");
      Serial.print(pitchDist);
      Serial.print(" | VolumeDist: ");
      Serial.println(volumeDist);

      // Convert distances to frequency and amplitude
      frequency = map(pitchDist, 5, 30, 800, 200);
      frequency = constrain(frequency, 100, 1000);

      amplitude = map(volumeDist, 5, 30, 255, 10);
      amplitude = constrain(amplitude, 0, 255);

      waveIncrement = 2 * PI * frequency / 100000.0; // for 100kHz update
    }
  }

  // Generate waveform at ~100 kHz
  unsigned long currentMicros = micros();
  if (currentMicros - prevMicros >= 10) {
    prevMicros = currentMicros;

    float wave = sin(wavePhase) * amplitude + 127;
    dacWrite(dacPin, (int)wave);

    wavePhase += waveIncrement;
    if (wavePhase >= 2 * PI) wavePhase -= 2 * PI;
  }
}
