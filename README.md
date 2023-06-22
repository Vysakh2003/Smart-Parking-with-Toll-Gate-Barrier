# Smart-Parking-with-Toll-Gate-Barrier

The objective of this project is to develop a simple IoT-based system using an IR sensor, an ultrasonic sensor, and lights to improve parking management and toll booth operations, incorporating three main functionalities: toll booth vehicle detection, accurate parking detection or distance measurement, and LED control based on parking distances.

COMPONENTS USED:
- ✔ Arduino UNO
- ✔ IR sensor
- ✔ Ultrasonic sensor
- ✔ Servo Motor
- ✔ LEDS
- ✔ some Wires

This system combines various components to enhance toll booth and parking operations.

- For toll booth operation, an IR sensor is used to detect vehicles. When the IR sensor detects an object, a servo motor turns to allow the vehicle to pass. If no object is detected, the servo motor remains stationary.

- In parking management, an ultrasonic sensor measures the distance between a vehicle and the parking area. Based on this distance measurement, LEDs are used to indicate the status. If the vehicle has not reached the desired threshold distance, a Green LED lights up. Once the vehicle reaches the threshold distance, a Red LED is activated.

By implementing these features, the system improves traffic flow and provides clear visual cues for drivers during toll booth operations and parking maneuvers.
