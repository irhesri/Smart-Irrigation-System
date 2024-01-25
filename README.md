# Smart Irrigation System

# Project Overview:

# Table of Contents

- [Part 1: Irrigation System](https://github.com/irhesri/Smart-Irrigation-System/tree/main#part-1-irrigation-system)
  - [Equipments](https://github.com/irhesri/Smart-Irrigation-System/tree/main#equipments)
    - [Soil Moisture Sensor](https://github.com/irhesri/Smart-Irrigation-System/tree/main#i--soil-moisture-sensor)
      - [Introduction](https://github.com/irhesri/Smart-Irrigation-System/tree/main#1-introduction)
      - [Specifications](https://github.com/irhesri/Smart-Irrigation-System/tree/main#2-specifications)
      - [Mounting](https://github.com/irhesri/Smart-Irrigation-System/tree/main#3-mounting)
      - [Code Functions](https://github.com/irhesri/Smart-Irrigation-System/tree/main#4-code-functions)
    - [Relay](https://github.com/irhesri/Smart-Irrigation-System/tree/main#ii--relay)
      - [Introduction](https://github.com/irhesri/Smart-Irrigation-System/tree/main#1-introduction-1)
      - [Specifications](https://github.com/irhesri/Smart-Irrigation-System/tree/main#2-specifications-1)
      - [Mounting](https://github.com/irhesri/Smart-Irrigation-System/tree/main#3-mounting-1)
      - [Code Functions](https://github.com/irhesri/Smart-Irrigation-System/tree/main#4-code-functions-1)
    - [Pump](https://github.com/irhesri/Smart-Irrigation-System/tree/main#iii--pump)
      - [Introduction](https://github.com/irhesri/Smart-Irrigation-System/tree/main#1-introduction-2)
      - [Specifications](https://github.com/irhesri/Smart-Irrigation-System/tree/main#2-specifications-1)
      - [Mounting](https://github.com/irhesri/Smart-Irrigation-System/tree/main#3-mounting-1)
      - [Code Functions](https://github.com/irhesri/Smart-Irrigation-System/tree/main#4-code-functions-2)
  - [Mounting](https://github.com/irhesri/Smart-Irrigation-System/tree/main#mounting)
- [Part2: Humidity and Temperature Display](https://github.com/irhesri/Smart-Irrigation-System/tree/main#part2-humidity-and-temperature-display)
  - [Equipments](https://github.com/irhesri/Smart-Irrigation-System/tree/main#equipments-1)
    - [DHT11](https://github.com/irhesri/Smart-Irrigation-System/tree/main#i--dht11)
      - [Introduction](https://github.com/irhesri/Smart-Irrigation-System/tree/main#1-introduction-3)
      - [Specifications](https://github.com/irhesri/Smart-Irrigation-System/tree/main#2-specifications-3)
      - [Mounting](https://github.com/irhesri/Smart-Irrigation-System/tree/main#3-mounting-3)
      - [Code Functions](https://github.com/irhesri/Smart-Irrigation-System/tree/main#4-code-functions-3)
    - [LCD 16x2 I2C](https://github.com/irhesri/Smart-Irrigation-System/tree/main#ii--lcd-16x2-i2c)
      - [Introduction](https://github.com/irhesri/Smart-Irrigation-System/tree/main#1-introduction-4)
      - [Specifications](https://github.com/irhesri/Smart-Irrigation-System/tree/main#2-specifications-4)
      - [Mounting](https://github.com/irhesri/Smart-Irrigation-System/tree/main#3-mounting-4)
      - [Code Functions](https://github.com/irhesri/Smart-Irrigation-System/tree/main#4-code-functions-4)
  - [Mounting](https://github.com/irhesri/Smart-Irrigation-System/tree/main#mounting-1)
- [Notes](https://github.com/irhesri/Smart-Irrigation-System/tree/main#memo-note)

# Part 1: Irrigation System
In this part we are gonna assemble the components and develop a code to enable the arduino to collect soil moisture data in order to determine whether to turn on or, off pump. Upon detecting a low moisture level, the Arduino must intervene by activating the pump to supply water for the plant.
## Equipments

### I- Soil Moisture Sensor:
>>>>>>>>>> ---
   #### *1. Introduction:*
  A soil moisture sensor is capable of measuring the moisture content in the   surrounding soil. It proves to be a valuable tool for keeping track of your garden or plant's water levels, making it an essential component of a smart garden.
  
<p align="center">
  <img alt="soil moisture sensor" src="https://github.com/irhesri/Smart-Irrigation-System/blob/main/Part1%3A%20Irrigation%20System/Equipments/Soil%20Moisture%20Sensor.jpg">
</p>

This sensor employs two probes to transmit current through the soil and subsequently gauge the resistance to determine the moisture level. Increased water content enhances soil conductivity, resulting in easier electricity flow (lower resistance), whereas dry soil exhibits poor conductivity, leading to higher resistance.
  #### *2. Specifications:*
  - Required voltage for working: 5V
  - Required current for working: <20mA
  - Required working temperature: 10°C~30°C
  - Type of interface: Analog
  - Depth of detection: 37mm
  #### *3. Mounting:* 
  
<p align="center">
  <img alt="soil moisture sensor mounting" src="https://github.com/irhesri/Smart-Irrigation-System/blob/main/Part1%3A%20Irrigation%20System/Equipments/Soil%20Moisture%20Sensor.png">
</p>

  #### *4. Code Functions:*
In order to use our moisture sensors it is necessary for us to perform a calibration process. It appears that each of these devices possesses its qualities and even sensors obtained from the same batch may have varying characteristics.
  :bulb: **Sensor Calibration**:
Calibration is a straightforward procedure involving determining the sensor's analog output under two conditions:
Dry Value - Exposed to air with minimal humidity.
Wet Value - Completely submerged in water.
- The calibration code is quite simple. In our code, we merely read the sensor value and print it to the serial monitor. After a brief pause, we repeat the entire process:
  
  ```
  #define sensor_pin A0

  void  setup() {
  Serial.begin(9600);
  }

  void  loop() {
    int  sensor_analog = analogRead(sensor_pin);
    Serial.println(sensor_analog);
    delay(1000);
  }
  ```
  Run the code and keep an eye on the serial monitor. Record the values in both damp and dry environments.
  
 *Dry Value*
 
  <p align="center">
    <img alt="serial monitor dry value" src="https://github.com/irhesri/Smart-Irrigation-System/blob/main/Part1%3A%20Irrigation%20System/Code/SensorDryValue.png">
  </p>
  
  *Wet Value*
  
   <p align="center">
    <img alt="serial monitor wet value" src="https://github.com/irhesri/Smart-Irrigation-System/blob/main/Part1%3A%20Irrigation%20System/Code/SensorWetValue.png">
   </p>
   
  1- Read sensors values:
  ```
  moistureValue = analogRead(moistureSensorPin);
  ```

  2- Determine soil moisture percentage:
  ```
  moisturePercentage = map(moistureValue, DryValue, WetValue, 0, 100);
  ```
  
  3- Make sure that the value is between 0 and 100:
  ```
  moisturePercentage = constrain(moisturePercentage, 0, 100);
  ```
  ### II- Relay:
>>>>>>>>>> ---
  #### *1. Introduction:*
  The 5V relay is an electromechanical switch that enables the Arduino Uno to regulate devices, such as water pumps, based on low-power signals. In the smart irrigation system, the relay serves as the interface between the Arduino Uno and the irrigation mechanism, enabling the automated activation and deactivation of the pump.
  
   <p align="center">
      <img alt="relay 5v" src="https://github.com/irhesri/Smart-Irrigation-System/blob/main/Part1%3A%20Irrigation%20System/Equipments/Relay%205v.jpg">
   </p>

  #### *2. Specifications:*
  - Required voltage for working: 5V
  - Type of interface: Digital
  #### *3. Mounting:*
  
  <p align="center">
    <img alt="relay mounting" src="https://github.com/irhesri/Smart-Irrigation-System/blob/main/Part1%3A%20Irrigation%20System/Equipments/Relay%205v.png">
  </p>
  
  #### *4. Code Functions:*
  - Turn on the relay :
  ```
  digitalWrite(relayPin, LOW);
  ```
  
  - Turn off the relay:
  ```
  digitalWrite(relayPin, HIGH);
  ```

  ### III- Pump:
>>>>>>>>>> ---
  #### *1. Introduction:*
  A soil moisture sensor is capable of measuring the moisture content in the   surrounding soil. It proves to be a valuable tool for keeping track of your garden or plant's water levels, making it an essential component of a smart garden.
  
  <p align="center">
    <img alt="pump" src="https://github.com/irhesri/Smart-Irrigation-System/blob/main/Part1%3A%20Irrigation%20System/Equipments/Pump%20120L-h.jpg">
  </p>
  
  #### *2. Specifications:*
  - Required voltage for working: 5V
  - Required current for working: 130-220mA
  - Flow rate:    80-120L/H
  #### *3. Mounting:*
  
  <p align="center">
    <img alt="pump mounting" src="">
  </p>
  
  #### *4. Code Functions:*
  > By operating the relay we have the ability to manage the pump. When the relay is deactivated the pump turns OFF. When it is activated the pump starts running.

  ## Mounting
  
  <p align="center">
    <img alt="irrigation system mounting" src="https://github.com/irhesri/Smart-Irrigation-System/blob/main/Part1%3A%20Irrigation%20System/Irrigation%20system.png">
  </p>

# Part2: Humidity and Temperature Display
In this part the arduino system is equipped with a sensor that measures the temperature and humidity of the air. These data are then displayed on an LCD screen integrated into the device. 

## Equipments

### I- DHT11:
>>>>>>>>>> ---
   #### *1. Introduction:*
The DHT11 is a temperature and humidity sensor widely used in electronic projects. It can measure both the ambient temperature and the relative humidity of the environment in which it is placed.
 - Temperature Measurement: The DHT11 sensor can provide an accuracy of ±2°C in the temperature range of 0°C to 50°C.

 - Humidity Measurement: The DHT11 sensor can provide an accuracy of ±5% in the humidity range of 20% to 80%.

  <p align="center">
    <img alt="DHT11" src="https://github.com/irhesri/Smart-Irrigation-System/blob/main/Part2%3A%20Humidity%20and%20Temperature%20Display/Equipments/DHT11%20sensor.jpg">
  </p>
  
   #### *2. Specifications:*
   - Required voltage for working: 3.3V to 5V
   #### *3. Mounting:*

  <p align="center">
    <img alt="DHT11 mounting" src="https://github.com/irhesri/Smart-Irrigation-System/blob/main/Part2%3A%20Humidity%20and%20Temperature%20Display/Equipments/DHT11%20Sensor.png">
  </p>
   
   #### *4. Code Functions:*
   
### II- LCD 16x2 I2C:
>>>>>>>>>> ---
   #### *1. Introduction:*
   This module combines a 16x02 LCD screen with an I2C interface module. The I2C module helps reduce the number of wires needed to connect the display to the Arduino.
   
  <p align="center">
    <img alt="LCD 16x2" width=49% src="https://github.com/irhesri/Smart-Irrigation-System/blob/main/Part2%3A%20Humidity%20and%20Temperature%20Display/Equipments/LCD%2016x02.jpg">
    <img alt="I2C adapter" width=49% src="https://github.com/irhesri/Smart-Irrigation-System/blob/main/Part2%3A%20Humidity%20and%20Temperature%20Display/Equipments/I2C%20Adapter%20for%20LCD.jpg">
  </p>

  ~ After soldering:
  <p align="center">
    <img alt="LCD 16x2 I2C front" width=49% src="https://github.com/irhesri/Smart-Irrigation-System/blob/main/Part2%3A%20Humidity%20and%20Temperature%20Display/Equipments/LCD%2016x02%20I2C%20front.jpg">
    <img alt="LCD 16x2 I2C back" width=49% src="https://github.com/irhesri/Smart-Irrigation-System/blob/main/Part2%3A%20Humidity%20and%20Temperature%20Display/Equipments/LCD%2016x02%20I2C%20Back.jpg">
  </p>
  
   #### *2. Specifications:*
   - Required voltage for working: 5V
   - Adresse I2C : 0x27
   
   #### *3. Mounting:*

  <p align="center">
    <img alt="LCD I2C mounting" src="https://github.com/irhesri/Smart-Irrigation-System/blob/main/Part2%3A%20Humidity%20and%20Temperature%20Display/Equipments/LCD%2016x2%20I2C.png">
  </p>
   
   #### *4. Code Functions:*

## Mounting
  
  <p align="center">
    <img alt="DHT11 & LCD mounting" src="https://github.com/irhesri/Smart-Irrigation-System/blob/main/Part2%3A%20Humidity%20and%20Temperature%20Display/Temp%20%26%20humidity.png">
  </p>
  
># :memo: Note:
> 
>The schems are made using [fritzing](https://fritzing.org/download/).
> 
> The material and the images are from [micro-planet](https://www.micro-planet.ma/produit/module-wifi-esp8266-esp-01/) and [marocproduit](https://marocproduits.com/)
