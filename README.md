# ESP32-Burglar-Alarm-System-HC-SR04-LCD-Buzzer


An embedded systems project built with the ESP32, HC-SR04 ultrasonic sensor, 16×2 LCD, push button, and buzzer to demonstrate a simple burglar alarm system with an activatable safe mode.

When Safe Mode is enabled, the system continuously measures the distance in front of the ultrasonic sensor. If an object is detected within the configured distance of 20 cm, the buzzer sounds and the LCD displays an object detection warning.

The alarm can be stopped by removing the object from in front of the sensor or pressing the push button to disable Safe Mode.

✨ Features

🛡️ Safe Mode: Activate or deactivate the alarm system using a push button.

📡 Ultrasonic detection: Measures the distance to objects using the HC-SR04 sensor.

🚨 Automatic alarm: Activates the buzzer when an object is detected within the configured threshold.

🖥️ Real-time status display: Shows Safe Mode status and object detection messages on a 16×2 LCD.

🔘 Manual deactivation: Turn off Safe Mode using the push button.

🔇 Automatic alarm stopping: The buzzer stops sounding when the detected object is removed beyond the detection threshold.

📊 Serial monitoring: Sends measured distance values to the Serial Monitor for debugging.
Important hardware note: GPIO 34 on the ESP32 is input-only, which makes it suitable for the ECHO signal. However, the standard HC-SR04 ECHO output can be approximately 5 V, while ESP32 GPIOs are not 5 V tolerant. Use a suitable voltage divider or level shifter between ECHO and GPIO 34. Also verify the LCD's logic-level compatibility and use a suitable driver if the buzzer requires more current than an ESP32 GPIO can provide.                                                                                         ⚙️ How It Works

1. System starts in Safe Mode OFF                   2. Activate Safe Mode             3. Detect an object       4. Stop the alarm           🛠️ Software and Development Environment

Programming language: C++ (Arduino framework)

Microcontroller: ESP32

Development environment: Arduino IDE
