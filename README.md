# Smart-Hospital-Bottle-
###Iot and Automation
###Our solution
Our solution is a reusable cap designed to work with IV bottles. The device is used to monitor patients' electrolyte levels in real-time and provide personalized care based on their individual needs. 

The hospital will have a centralized control unit where they can access all data of each bottle through their unique ID. There is a customized app specially devised so that the individual personnel can access the information on the IV drip bottle level. The app provides insight on the level, real-time data with the entire history of the level of the IV drip.

In case the level drops below the critical levels, an alert signal would be sent through the app plus a buzzer would be activated. This would alert the nurse to check the bag immediately.


### Technology used
We used Firebase as our database and cloud to receive data and send data to mobile app using API. 
We use Blynk for Application development. The app will include live status update, adding more devices or bottles, monitoring patient and push notifications for alerts. 
Arduino IDE will be used to communicate with the microcontroller, cloud and Thing-Speak will be used for live status visualisation of the data
We use ESP32 Development Board with Wifi and Bluetooth as microcontroller to connect to the sensor and send data to the cloud.
Ultrasonic sensor which is a Level sensor is used for level measuring of the liquid irrespective of the type or density of liquid. This would be used to detect the distance at which the fluid is present. This would help in the continuous monitoring of fluid levels in the IV Bottle. 
There is a buzzer included in the circuit to alert when the level is below the critical level 

### Features
The unique cap has an ultrasonic sensor for distance and level measurement. The ultrasonic sensor sends data to the ESP32 which is WIFI enabled so the data can be accessed through the database and app. The data is also dynamically visualized through Thingspeak. 
The app’s main functionality is to provide an alert to the personnel through notifications in the app. Due to the critical and importance of constant monitoring, the alert stays till the problem isn't rectified. 
The control unit has a firebase cloud as its center with parameters like alert and level. This data can then be used for multiple purposes through the data JSON files.
There is buzzer for alert as a physical indication of the critical level.







