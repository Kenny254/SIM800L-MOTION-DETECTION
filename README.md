# SIM800L-MOTION-DETECTION
Sends a text every time it detects motion.
/
 *     This library use SoftwareSerial, you can define de RX and TX pin
 *     in the header "Sim800l.h" ,by default the pin is RX=10 TX=11..
 *     be sure that gnd is attached to arduino too. 
 *     You can also change the other preferred RESET_PIN
 *
 *     
 *    PINOUT: 
 *        _____________________________
 *       |  ARDUINO UNO >>>   SIM800L  |
 *        -----------------------------
 *            GND      >>>   GND
 *        RX  10       >>>   TX    
 *        TX  11       >>>   RX
 *       RESET 2       >>>   RST 
 
 PINOUT: 
 *        _____________________________
 *       |  ARDUINO UNO >>>   PIR SENSOR |
 *        -----------------------------
 *            GND      >>>   GND
 *             5V       >>>   Vin 3-5V
 *              2       >>>   2Sensor Input
 *                 
 *   POWER SOURCE 4.2V >>> VCC
 *
 *    Created on: OCT 20, 2018
 *        Author: Ken Ronoh
 * 
*/
