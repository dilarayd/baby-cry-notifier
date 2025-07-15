# Baby Cry Notification System

This project is an IoT-based baby cry notification system that uses a sound sensor to detect crying and sends **real-time alerts** to parents via a Telegram bot using the ESP32 board.

---

## Purpose

- Sends a Telegram message **"Baby has started crying!"** when crying is detected.  
- Sends another message like **"Baby stopped crying. Duration: X seconds"** when crying ends.  
- Allows parents to remotely monitor their baby.

---

## Hardware Used

- ESP32 Development Board  
- LM393 Digital Sound Sensor  
- Breadboard  
- Jumper Wires  
- USB Power Supply  
- Telegram Bot & App

---

## How It Works

1. Sound sensor detects crying (produces a LOW signal).  
2. ESP32 connects to WiFi.  
3. Sends a message via the Telegram bot.  
4. When crying stops, calculates duration and sends a follow-up message.

---

## Project Team

- Dilara AYDIN  
- İlayda ÖZHAN  
- Ömer Faruk LİMON

---


---

# Bebek Ağlama Bildirim Sistemi

Bu proje, ses sensörü kullanarak bebek ağlamasını algılayan ve ESP32 üzerinden Telegram bot aracılığıyla ebeveynlere **anlık bildirim** gönderen bir IoT sistemidir.

---

## Amaç

- Bebek ağladığında Telegram üzerinden **“Bebek ağlamaya başladı!”** bildirimi gönderilir.  
- Ağlama sona erdiğinde, ağlama süresiyle birlikte **“Bebek ağlaması sona erdi”** mesajı gönderilir.  
- Ebeveynlerin bebeği uzaktan takip etmesini sağlar.

---

## Kullanılan Malzemeler

- ESP32 Geliştirme Kartı  
- LM393 Dijital Ses Sensörü  
- Breadboard  
- Jumper Kablolar  
- USB Güç Kaynağı  
- Telegram Bot ve Uygulama

---

## Çalışma Prensibi

1. Ses sensörü ağlamayı algılar (LOW sinyali üretir).  
2. ESP32 WiFi ağına bağlanır.  
3. Telegram botu üzerinden mesaj gönderilir.  
4. Ağlama sona erdiğinde süre hesaplanarak ikinci bir mesaj gönderilir.

---

## Proje Ekibi

- Dilara AYDIN  
- İlayda ÖZHAN  
- Ömer Faruk LİMON


