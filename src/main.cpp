#include <WiFi.h>
#include <Arduino.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "DHT.h"

#define DHTPIN 5
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

const char *ssid = "SSID";
const char *password = "Passw@rd";

// Domain Name with full URL Path for HTTP POST Request
const char *serverName = "http://192.168.0.1:8086/write?db=iot";

// Timer set to 30 seconds
unsigned long lastTime = 0;
unsigned long timerDelay = 30000;

void sendData(float humidity, float temperature)
{
  Serial.println("Prepare to send data");

  String httpRequestData = "iot,room=outside,device=SolarEsp32 temperature=" + String(temperature) + ",humidity=" + String(humidity);
  Serial.println(httpRequestData);

  HTTPClient http;
  // Your Domain name with URL path or IP address with path
  http.begin(serverName);
  http.addHeader("Content-Type", "application/Text");
  http.addHeader("Authorization", "Token admin:strongpassword123QWE");
  // Data to send with HTTP POST
  
  // Send HTTP POST request
  int httpResponseCode = http.POST(httpRequestData);

  Serial.print("HTTP Response code: ");
  Serial.println(httpResponseCode);

  // Free resources
  http.end();
  Serial.println("Sent");
}

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  dht.begin();
  Serial.println("Connected dht");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // Waiting for connection to wifi
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop()
{
  // Reading temperature or humidity takes about 250 milliseconds!
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%  Temperature: ");
  Serial.print(temperature);
  Serial.println("°C ");

  if ((millis() - lastTime) > timerDelay)
  {
    Serial.println("its time");
    // Check WiFi connection status
    if (WiFi.status() == WL_CONNECTED)
    {
      Serial.println("WiFi connected, send!");
      sendData(humidity, temperature);
    }
    else
    {
      Serial.println("WiFi Disconnected");
    }

    lastTime = millis();
  }

  delay(5000);
}
