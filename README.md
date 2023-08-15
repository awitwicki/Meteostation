# Meteostation
This is a PlatformIO project for ESP32 that reads temperature and humidity data from a DHT11 sensor connected to Pin 5 and sends the data to an InfluxDB server at regular intervals.

## Prerequisites

- [PlatformIO](https://platformio.org/) installed on your system.
- An ESP32 development board.
- DHT11 sensor.
- InfluxDB server accessible on your network.

## Setup

### Code
Type your influxdb query in main.cpp, wifi SSID and password


### Pin Connection
Connect the DHT11 sensor to Pin 5 on your ESP32 board.

### Usage
The ESP32 will read temperature and humidity data from the DHT11 sensor every 30 seconds and send it to your InfluxDB server. You can customize the interval and other settings in the code.

### Troubleshooting
Make sure your WiFi credentials and InfluxDB settings are correct.
Verify the pin connections.
Check the serial output for any error messages.

### License
This project is licensed under the MIT License.
