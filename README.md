RobotSensorLibrary
==================

 - Triggering LEDs on a Launchpad to check IR Sensor Operation and Functionality

 - IR Sensor on Robot - A/D Conversion

The purpose of this repository is to provide code to gather IR Sensor information on a robot. The code provided gives sensor readings to the left and right sensors of the US Air Force Academy robot. Most important to note is that a digital multimeter or a way to measure voltage is absolutely necessary to accomplish readings on the sensors. These readings provide a voltage from 0-5Volts which are needed to determine the hexidecimal values you want for your robot to get close to the wall or not too close. Overall this code will provide an example of the sensors working as they will light up LEDs on the MSP430 Launchpad which will signal whether the left or right sensors are being triggered for being above the coded voltage threshold "your voltage readings". 

##Hardware Required
 - MSP430 Microcontroller Chip (G2553 Series)
 - Robot issued by the United States Air Force Academy
 - LDV33 3.3V Regulator
 - 100 Micro Farad Capacitor
 - Motor Driver Chip, any will do fine, as long as it can withstand the voltages

##Stepping Through Operation

 - You need to accomplish a few things before you start coding. I know you are very eager to get sensor readings so bare with me for a few minutes as I walk you through the steps to be accomplished before we jump into sensor code. First we need to check to see if the sensors work right. Plug the appropriate voltage wire and ground to the robot sensors (left and right and center) and place the sensor in front of an obstable, I would say fairly close if you want to get a good reading, about 4-6 inches should suffice. Check your voltage reading on the digital multimeter. Remember that your robot handles from 0-5 Volts. My reading was approximately 2.6 Volts. You divide this voltage by 5. Multiply your value about (0.5...) by 1024 to give you a decimal value. Convert this decimal value to hexidecimal and this will give you the proper hex value the sensors look for as the treshhold for the LEDs on the MSP430 LaunchPad to trigger on or off. 
 
 - For required functionality, you need to be able to make the LEDs on the launchpad light up, the left one on for left sensor reading and the right LED on for the right sensor reading. Once this is achieved, you have achieved required functionality. This is important for the robot maze navigation in my next repository. 
 
 - For B Functionality, create your own library and publish it to GitHub. Help others achieve this! If you have any comments on how to better my lab or code, please contact me, I am always up to any advice.

##Functions

This will give you some guidance on what my code does and why I use the fucntions I use...

```
void initADC10();
```

 - This piece of code with initialize the ADC10 interrupt on the MSP430. This is very important for getting readings on the sensors. 

```
void initLEDs();
```

 - Initializing the LEDs is very imporant. This is tell the MSP430 to send readings to the LEDs on the launchpad to trigger on. This is the whole purpose of the exercise! Take left or right sensor readings adn trigger the appropriate LED on the launchpad!

```
unsigned int leftsensor();
```

 - This sets the BIT to be triggered when readings from the left sensor are taken. This will also return to the main.c part of the code where it checks the voltage threshold in ADC10MEM.

```
unsigned int rightsensor();
```

 - This part of the code is the same as left except we declare BIT4 to take the readings from the right sensor. IT will send information to ADC10MEM on main.c to trigger the correct LED.


##Documentation

I recieved help from C2C Ryan Good on coding. He directed me on what to do for the left sensor and right sensor part of my code. I also recieved help from C2C Michael Bentley who showed me how to calculate my voltage threshold for the sensor boundaries. 

##Lisencing

Feel free to use my code! If you have any changes or concers feel free to contact me. I am always looking for new advice on becoming a great programmer!




 
 

