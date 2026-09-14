# ESP32 Air Quality & Gas Monitor

A real-time environmental monitoring node built with an ESP32 and an MQ-135 gas sensor. The system reads analog air quality data, tracks baseline ambient levels, and detects air contaminants (like alcohol vapors, smoke, and hazardous gases) with live alerts over the Serial Monitor.

---

## Photos & Live Testing

<!-- Drag and drop your board photo and serial monitor photo right below this line! -->


---

## How It Works

1. Sensing: The MQ-135 sensor uses an internal heating coil and a gas-sensitive layer. In clean air, its electrical resistance stays high; when airborne contaminants hit the sensor, resistance drops and voltage increases.
2. Signal Acquisition: The ESP32's built-in 12-bit Analog-to-Digital Converter (ADC) samples pin `GPIO 34` once per second, turning the electrical signal into a digital count from `0` to `4095`.
3. Threshold Logic: The firmware compares real-time counts against ambient room baselines:
   < 120 ADC (~0.06V): Clean Air
   120 – 300 ADC: Light Gas / Distant Source Detected
   > 300 ADC: Strong Gas Concentration Detected


## Hardware & Pinout

| Sensor Pin | ESP32 Pin | Purpose |
| :---    | :--- | :--- |
|   VCC   | `VIN` (5V) | Powers the sensor heating element |
|   GND   | `GND` | Shared system ground |
|   AO    | `GPIO 34` | Analog voltage signal into the ESP32 |
<img width="3840" height="5120" alt="WhatsApp Image 2026-09-14 at 10 40 53" src="https://github.com/user-attachments/assets/ca31b469-bb71-4cba-848a-5affdf400c62" />
<img width="2922" height="5120" alt="WhatsApp Image 2026-09-14 at 10 40 56" src="https://github.com/user-attachments/assets/128a1bd3-6858-40d7-9001-1a1ee1041fff" />
<img width="2751" height="2535" alt="WhatsApp Image 2026-09-14 at 10 40 59" src="https://github.com/user-attachments/assets/0ee83771-c8ef-451b-b702-2666cee2adef" />
<img width="3840" height="5120" alt="WhatsApp Image 2026-09-14 at 10 41 02" src="https://github.com/user-attachments/assets/63be771a-a7b3-435e-aaa9-42406440eae7" />

