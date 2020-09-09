# ESP32 anylyse IR remote control protocols
Implement analyse IR remote control protocols for ESP32 boards with Arduino framework

Last update: September 2020

#### Development notes
- If you start a new Platformio project, use:
```bash
# put this line in platformio.ini :
monitor_speed = 115200 
# to fix could not open port /dev/ttyUSB0: [Errno 13] Permission denied: '/dev/ttyUSB0', open terminal and write:
sudo chmod a+rw /dev/ttyUSB0
```
#### Tools used:
- __Platformio__ (https://platformio.org)
- __VScode__ (https://code.visualstudio.com)
- __ESP-IDF__ (https://docs.espressif.com/projects/esp-idf/en/stable/get-started/) 
- __M5StickC__ , but you can use other dev board:    
   - For the Detailed documentation of M5StickC, please click [here](https://docs.m5stack.com/#/en/core/m5stickc)
   - In order to buy M5StickC, please click [here](https://www.aliexpress.com/item/New-Arrival-2019-M5StickC-1-of-Limited-Trial-Edition-ESP32-PICO-Mini-IoT-Development-Board-Finger/32985247364.html)
   - Description: <mark>**M5StickC**</mark> is a ESP32 development board with 0.96 inch **TFT color screen** (80 * 160 resolution), **Red LED**, button, **Microphone**, IR transmitter, 6-axis IMU (SH200Q) and 80 mAH battery. The ESP32 module **[ESP32-Pico](https://github.com/m5stack/M5-Schematic/blob/master/Core/esp32-pico-d4_datasheet_en.pdf)** in M5StickC also has a built-in 4MB flash. If the M5StickC is equipped with watch-base and watch-belt, you can wear it on your wrist.
   - PinMap:  
   
**Red LED & IR transmitter & BUTTON A & BUTTON B**
<table>
 <tr><td>ESP32 chip</td><td>GPIO10</td><td>GPIO9</td><td>GPIO37</td><td>GPIO39</td></tr>
 <tr><td>Red LED</td><td>LED pin</td><td> </td><td> </td><td> </td></tr>
 <tr><td>IR transmitter</td><td> </td><td>transmitter pin</td><td> </td><td> </td></tr>
<tr><td>BUTTON A</td><td> </td><td> </td><td>button pin</td><td> </td></tr>
<tr><td>BUTTON B</td><td> </td><td> </td><td> </td><td>button pin</td></tr>
</table>
**TFT Screen**

*Driver IC: [ST7735S](https://github.com/m5stack/M5-Schematic/blob/master/Core/ST7735S_v1.1.pdf)*

*Resolution: 80 * 160*

<table>
 <tr><td>ESP32 chip</td><td>GPIO15</td><td>GPIO13</td><td>GPIO23</td><td>GPIO18</td><td>GPIO5</td></tr>
 <tr><td>TFT Screen</td><td>TFT_MOSI</td><td>TFT_CLK</td><td>TFT_DC</td><td>TFT_RST</td><td>TFT_CS</td></tr>
</table>

**GROVE interface**

<table>
 <tr><td>ESP32 chip</td><td>GPIO33</td><td>GPIO32</td><td>5V</td><td>GND</td></tr>
 <tr><td>GROVE interface</td><td>SCL</td><td>SDA</td><td>5V</td><td>GND</td></tr>
</table>

**Microphone ([SPM1423](https://github.com/m5stack/M5-Schematic/blob/master/Core/SPM1423HM4H-B.pdf))**

<table>
 <tr><td>ESP32 chip</td><td>GPIO0</td><td>GPIO34</td></tr>
 <tr><td>Microphone</td><td>SCL</td><td>SDA</td></tr>
</table>

**6-axis IMU ([SH200Q](https://github.com/m5stack/M5-Schematic/blob/master/Core/SH200Q.pdf)) & Power Mangement IC ([AXP192](https://github.com/m5stack/M5-Schematic/blob/master/Core/AXP192%20Datasheet%20v1.13_cn.pdf))**

<table>
 <tr><td>ESP32 chip</td><td>GPIO22</td><td>GPIO21</td>
 <tr><td>6-axis IMU (SH200Q)</td><td>SCL</td><td>SDA</td>
 <tr><td>Power Mangement IC (AXP192)</td><td>SCL</td><td>SDA</td>
</table>

**M5StickC top extended IO port**

<img src="https://m5stack.oss-cn-shenzhen.aliyuncs.com/image/m5-docs_content/core/m5stickc_04.png" alt="M5StickC_04">

### If you need any help or information:
:large_blue_circle:	 Facebook: https://www.facebook.com/walidamriou   
:large_blue_circle:  Twitter: https://twitter.com/walidamriou    
:large_blue_circle:  Linkedin: https://www.linkedin.com/in/walidamriou  
:red_circle: Email:  contact [at] walidamriou [dot] com    

### Copyright CC 2020 Walid Amriou

<a rel="license" href="http://creativecommons.org/licenses/by-nc-nd/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-nd/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-nd/4.0/">Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License</a>.

__You are free to:__
- __Share__ copy and redistribute the material in any medium or format

__Under the following terms:__
- __Attribution__ You must give appropriate credit, provide a link to the license, and indicate if changes were made. You may do so in any reasonable manner, but not in any way that suggests the licensor endorses you or your use.

- __NonCommercial__ You may not use the material for commercial purposes.

- __NoDerivatives__ If you remix, transform, or build upon the material, you may not distribute the modified material.

- __No additional restrictions__ You may not apply legal terms or technological measures that legally restrict others from doing anything the license permits.


the software or Code or Scripts or any files in this source is provided "as is" and the author disclaims all warranties with regard to this files including all implied warranties of merchantability and fitness. in no event shall the author be liable for any special, direct, indirect, or consequential damages or any damages whatsoever resulting from loss of use, data or profits, whether in an action of contract, negligence or other tortious action, arising out of or in connection with the use or performance of this software or code or scripts or any files in this source.

© The logo and the name and ideas of the project are owned by __Walid Amriou__, and do not fall under the open license for reconstruction, it must be preserved in full without modification. 
