# Arcanoid — STM32 Game Project 🎮

# PL

Klasyczna gra Arcanoid napisana w języku **C** dla mikrokontrolera **STM32F3**, z wykorzystaniem wyświetlacza **Nokia 5110 (PCD8544)** oraz joysticka.  
Projekt wykonany w **STM32CubeIDE**, w celach edukacyjnych i prezentacji umiejętności w zakresie systemów wbudowanych.

---

## 🛠️ Sprzęt i środowisko

- ✅ Płytka rozwojowa nucleo z mikrokontrolerem **STM32F303RET6**
- ✅ Wyświetlacz **Nokia 5110 / PCD8544**
- ✅ Joysticki analogowe
- ✅ Środowisko: **STM32CubeIDE** 

---

## 📦 Funkcje

   **Tryb singleplayer**
-  Obsługa kolizji piłki z otoczeniem
-  Zbijanie bloków
-  Zliczanie wyniku i wyświetlanie w czasie rzeczywistym
-  Mechanika żyć, restart/gameover
-  Możliwość zapauzowania rozgrywki
-  Trzy poziomy trudności EASY/MEDIUM/HARD
-  Buforowane rysowanie na LCD, odświeżanie 60Hz
   **Tryb multiplayer**
-  Do rozwoju w przyszłości
-  Gotowe przystosowanie kodu gry pod mechanikę bonusów i multi-buffering

---

## 📁 Struktura katalogów

Arcanoid---full-project/
├── Core/
│ ├── Inc/ # Pliki nagłówkowe 
│ ├── Src/ # Główna logika i obsługa gry
├── Drivers/ # HAL i CMSIS
├── STM32F303RETX_FLASH.ld
├── Arcanoid.ioc # Plik projektu CubeMX
├── .gitignore
└── README.md

Projekt stworzony przez papaj-23 jako część praktycznej nauki systemów embedded i STM32.

# ENG

A classic **Arcanoid game written in C** for the **STM32F3 microcontroller**, using a **Nokia 5110 (PCD8544) LCD** and analog joysticks.  
The project was developed in **STM32CubeIDE** for educational purposes and as a demonstration of embedded systems programming skills.

---

## 🛠️ Hardware & Environment

- ✅ Nucleo development board with **STM32F303RET6**
- ✅ **Nokia 5110 / PCD8544** LCD
- ✅ Analog joysticks
- ✅ Development environment: **STM32CubeIDE**

---

## 📦 Features

### **Singleplayer Mode**
- Ball collision detection
- Brick breaking mechanics
- Real-time score tracking and display
- Life system with restart and Game Over screen
- Pause functionality
- Three difficulty levels: **EASY / MEDIUM / HARD**
- Buffered LCD rendering at 60Hz

### **Multiplayer Mode**
- To be developed in the future
- Game code is already prepared for bonuses and multi-buffering logic

---

## 📁 Project Structure

Arcanoid---full-project/
├── Core/
│ ├── Inc/ # Header files
│ ├── Src/ # Game logic and runtime code
├── Drivers/ # HAL and CMSIS libraries
├── STM32F303RETX_FLASH.ld
├── Arcanoid.ioc # STM32CubeMX project file
├── .gitignore
└── README.md

Project created by **papaj-23** as part of practical learning in embedded systems and STM32 development.