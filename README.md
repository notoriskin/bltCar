# 🚗 bltCar – Arduino Nano Bluetooth Car with LEGO Integration

A **Bluetooth-controlled Arduino Nano car** featuring **toggle-based steering and driving**, designed to be embedded inside a **LEGO Technic 42039 Race Car Truck**. This project demonstrates modular robotics using LEGO Technic, DC motors, and servos, all controlled via a smartphone over Bluetooth.

---

## 🧭 Project Summary

This DIY smart car project enables remote steering and movement via a mobile device using an **HM-10 Bluetooth module**. It integrates:

- 🚙 **Steering control** using servo motors  
- ⚙️ **Drive control** using an L298N motor driver  
- 🧩 **LEGO chassis integration** with the Technic 42039 for a durable and modular frame

---

## 🔌 Key Components

- 🧠 **Arduino Nano** (space-saving form factor)  
- 📡 **HC-05 Bluetooth Module** (BLE)  
- ⚡ **L9110 Motor Driver**  
- 🔄 **fake Lego Servo motor** (steering)(by fake I mean that they not actually servo, as well as the fact they are knockoffs)) 
- 🚗 **Lego DC Motor** (driving)  
- 🔋 **2x 18650 Li-ion battery pack (7.4V)**  
- 🧱 **LEGO Technic 42039 Chassis**  
- 📱 **Android device** with Bluetooth serial controller (works better on Android, but Dabble app can be configured on iphone too)

---

## ⚙️ Wiring Schematics
![buttonsLR](https://github.com/user-attachments/assets/2e4d7d4e-328a-4f83-b655-cd2486d4a4cb)
<img width="989" alt="bltCar" src="https://github.com/user-attachments/assets/ba9621ff-ebb3-4107-84a1-5d0cc7524afd" />
<img width="732" alt="  2025-04-24 at 11 46 37 AM" src="https://github.com/user-attachments/assets/3861884f-0e91-4a48-a7c9-81120afd7546" />

### 🧠 Steering + Logic Circuit

![Servo + Button Schematic](insert-your-image-path-1)

### 🔋 Full Power & Motor Driver

![Motor Driver Schematic](insert-your-image-path-2)

---

## 🎥 Prototype Preview

![Working Demo Snapshot](insert-your-image-path-3)
![IMG_4725](https://github.com/user-attachments/assets/dba7a781-966f-4cd5-8355-3878f59b8cca)


Real Arduino Nano-based prototype controlling motor/steering through Bluetooth serial commands.

---

## 📲 Control Workflow

1. **Pair your Android phone** with the HM-10/HC-05 module  
2. **Launch Bluetooth serial controller app**  
3. Send characters like:
   - `"f"` → Forward  
   - `"b"` → Backward  
   - `"l"` / `"R"` → Steering toggle  
   - `"s"` → Stop  

Arduino parses these to update motor/servo states.

---

## 🧠 Educational Value

- 🔌 Learn BLE communication via HM-10  
- 🧭 Implement serial parsing in embedded C  
- 🔄 Control servo and DC motors together  
- 🧱 Repurpose LEGO Technic into a robotics platform  
- 🎮 Create your own control protocol
