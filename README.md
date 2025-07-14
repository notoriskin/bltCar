🛡️ bltTank – Arduino Nano Bluetooth Tank with Dual Motor Control

A Bluetooth-controlled Arduino Nano tank built on a crawler chassis, powered by 2 motor control for steering and movement. Like its sibling project bltCar, it uses the HC-05 Bluetooth module and a custom smartphone app for remote control.

⸻

🧭 Project Summary

This tracked vehicle offers precise control via phone using simple serial commands. Featuring:
	•	🛞 Dual DC motor drive for tank-like maneuvering (turns by rotating wheels in opposite directions)
	•	🧠 Arduino Nano brain for compact embedded control
	•	📱 Bluetooth control using a custom bltTank app or serial controller

⸻

🔌 Key Components
	•	🧠 Arduino Nano
	•	📡 HC-05 Bluetooth Module
	•	⚡ L298N Dual H-Bridge Motor Driver
	•	🛞 2x DC Motors (one per track [diaganally from each other])
	•	🔋 2x 18650 Li-ion battery pack (7.4V)
	•	🦾 Crawler Tank Chassis (eBay/AliExpress generic)
 
⸻

⚙️ Wiring Schematics

🔄 Motor & Power Schematic
Left Motor  → IN1, IN2 on L298N  
Right Motor → IN3, IN4 on L298N  
ENA/ENB     → Connected to Arduino D9/D10 for PWM control (optional)  
Bluetooth TX → Arduino RX  
Bluetooth RX → Arduino TX  
L298N VCC   → Battery +  
L298N GND   → Battery - and Arduino GND  

Example wiring:

IN1 = D3  
IN2 = D4  
IN3 = D5  
IN4 = D6  

⸻

🎥 Prototype Preview

![IMG_3857](https://github.com/user-attachments/assets/99c1587c-4a93-4a19-a6c8-03fb5fad79c0)


Working bltTank with rugged track movement via dual DC motors.

⸻
🧠 Educational Value
	•	🤖 Understand dual motor tank steering logic
	•	🔁 Practice serial communication and command parsing
	•	🔌 Integrate Bluetooth, PWM, and power routing
	•	🧱 Experiment with platform portability between tank and car designs
	•	📱 Design custom UIs for robotic control




