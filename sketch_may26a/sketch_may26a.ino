#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include "secrets.h"

#define SOUND_SENSOR_PIN 4

WiFiClientSecure client;
UniversalTelegramBot bot(BOT_TOKEN, client);

bool soundActive = false;
unsigned long lastMessageTime = 0;
unsigned long startCryingTime = 0; 
unsigned long silenceStartTime = 0; 
const long MESSAGE_DELAY = 10000; 
const long WIFI_TIMEOUT = 30000; 
const long SILENCE_THRESHOLD = 5000; 
bool wifiConnected = false;

void setup() {
  Serial.begin(115200);
  pinMode(SOUND_SENSOR_PIN, INPUT);

  WiFi.begin(ssid, password);
  Serial.println("WiFi baglantisi baslatildi...");
}

void loop() {
  if (!wifiConnected && WiFi.status() == WL_CONNECTED) {
    wifiConnected = true;
    Serial.println("\nWiFi connected!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    client.setInsecure();
  }

  int soundDetected = digitalRead(SOUND_SENSOR_PIN);

  Serial.print("Sensor degeri: ");
  Serial.println(soundDetected);

  if (soundDetected == LOW) { 
    if (!soundActive && (millis() - lastMessageTime >= MESSAGE_DELAY)) {
      soundActive = true;
      startCryingTime = millis(); 
      lastMessageTime = millis(); 
      Serial.println("Bebek aglamasi algilandi!");

      if (wifiConnected) {
        String message = "Bebek aglamaya basladi!";
        int sendStatus = bot.sendMessage(CHAT_ID, message, "");
        if (sendStatus) {
          Serial.println("Baslangic mesaji gonderildi!");
        } else {
          Serial.println("Baslangic mesaji gonderilemedi!");
        }
      } else {
        Serial.println("WiFi henüz baglanmadi, mesaj gonderilemedi!");
      }
    }
    silenceStartTime = 0; 
  } else if (soundDetected == HIGH && soundActive) { 
    if (silenceStartTime == 0) {
      silenceStartTime = millis();
    } else if (millis() - silenceStartTime >= SILENCE_THRESHOLD) {
      soundActive = false;
      unsigned long cryingDuration = (silenceStartTime - startCryingTime) / 1000; 
      lastMessageTime = millis(); 
      Serial.println("Bebek aglamasi sona erdi!");

      if (wifiConnected) {
        String message = "Bebek aglamasi sona erdi. Sure: " + String(cryingDuration) + " saniye";
        int sendStatus = bot.sendMessage(CHAT_ID, message, "");
        if (sendStatus) {
          Serial.println("Bitis mesaji gonderildi!");
        } else {
          Serial.println("Bitis mesaji gonderilemedi!");
        }
      } else {
        Serial.println("WiFi henüz baglanmadi, bitis mesaji gonderilemedi!");
      }
    }
  }

  delay(50);
}