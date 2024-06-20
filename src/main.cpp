#include "Arduino.h"
#include <WiFi.h>
#include "DHTesp.h"
#include "ThingSpeak.h"
#include <LiquidCrystal_I2C.h>

const int DHT_PIN = 33;
const char *WIFI_NAME = "Wokwi-GUEST";
const char *WIFI_PASSWORD = "";
const char *myApiKey = "G0UT9EEE1R1I9AHK";
const long unsigned int channelId = 2579162;
const char *server = "api.thingspeak.com";
// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

DHTesp dhtSensor;
WiFiClient client;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

void setup()
{
  Serial.begin(115200);
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);

  // initialize LCD
  lcd.init();
  // turn on LCD backlight
  lcd.backlight();

  lcd.setCursor(0, 0);
  // print message
  lcd.print("Connecting to WiFi!");

  WiFi.begin(WIFI_NAME, WIFI_PASSWORD, 6);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Wifi not connected");
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Wifi Connected");
  Serial.println("Wifi connected !");
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
  delay(2000);
}

long int updatedTime = millis();

void loop()
{
  long int currentTime = millis();
  lcd.clear();
  lcd.setCursor(0, 0);

  TempAndHumidity data = dhtSensor.getTempAndHumidity();

  if (currentTime - updatedTime > 15000)
  {
    ThingSpeak.setField(1, data.temperature);
    ThingSpeak.setField(2, data.humidity);
    int x = ThingSpeak.writeFields(channelId, myApiKey);
    if (x == 200)
    {
      Serial.println("Data pushed successfull");
    }
    else
    {
      Serial.println("Push error" + String(x));
    }
    Serial.println("---");
    updatedTime = currentTime;
  }

  lcd.print("Temp: " + String(data.temperature, 2) + "°C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: " + String(data.humidity, 1) + "%");
  delay(1000);
}