# Wireless Power Transfer - CAPSTONE Project
![WhatsApp Image 2024-08-05 at 20 47 46_10204884](https://github.com/user-attachments/assets/5495943a-a398-43e7-8adc-f6aa76c80092)
This is repository for a Wireless Power Transfer. I have completed this project in semester 6 as an assignment for the CAPSTONE course. In this repository there are three PCB board that I design using KiCad 7.0. The boards are 12V Fullbridge Inverter, transmitter-board, and receiver-board. 
## Important notes !!!
This repository file management maybe kinda messy. But you can find 12V Fullbridge inside the directory:
```bash
.\full-bridge-inverter\full-bridge-inverter
```
That directory also includes Proteus simulation and source code for Arduino Nano.

Transmitter-board inside the directory:
```bash
.\transmitter-board
```
and receiver-board inside the directory:
```bash
.\receiver-board
```
## 1. 12V Fullbridge Inverter
This full-bridge inverter can convert 12VDC to 12VAC with a frequency ranging from 80kHz to 200kHz. This inverter is controlled by an Arduino Nano as the PWM generator. On the bottom left side of the board, you can adjust the frequency, and the value will be shown on the 0.91-inch OLED display.
### Simulation
Below is the simulation at maximum frequency (200kHz):
![image](https://github.com/user-attachments/assets/afc9e49a-46b2-4c7e-9c28-9b5b6cfe2198)

Below is the simulation at minimum frequency (80kHz):
![image](https://github.com/user-attachments/assets/82c85dc3-de97-45eb-b896-e2319ef05174)

### Schematic
![Preview](https://github.com/user-attachments/assets/31e1ac72-53bd-4ae8-9b04-e3bb2d53729e)

### Layout
![image](https://github.com/user-attachments/assets/5a9439ab-6a82-43c0-8e99-308c91e7b08e)

### Board Image
![image](https://github.com/user-attachments/assets/6c502590-a65c-4387-b915-ec994fec6f1c)
![WhatsApp Image 2024-08-05 at 19 57 58_32873d33](https://github.com/user-attachments/assets/036f6fcd-84ba-4ada-b16d-578c1fc10dec)

### Specification
| Input Voltage | Output Voltage | Max Output Current | Operating Frequency |
| :---: | :---: | :---: | :---: |
| 5VDC - 15VDC | 7VAC - 15VAC | 3A | 80kHz - 200kHz* |

*operating frequency can be changed by program up to 1MHz
## 2. Transmitter Board
This transmitter board uses an LC series connection. This configuration helps reduce its impedance so the current flow can be maximized. The capacitor can be added or replaced with another one since the board uses an XT30 connector for the capacitor. The capacitor value needs to be calculated based on the resonant frequency to achieve maximum power transfer.

![image](https://github.com/user-attachments/assets/30e67a79-52a8-4c15-bbc3-37252ab57ece)

### Schematic
![image](https://github.com/user-attachments/assets/5115ecc7-ddd4-4528-b692-6c4087b33575)

### Layout
![image](https://github.com/user-attachments/assets/8ad4de3a-b9e5-4369-8954-2d1eb7726096)

### Board Image
![image](https://github.com/user-attachments/assets/d9f1b366-c337-43ff-bc5b-23e2ef19633c)
![WhatsApp Image 2024-08-05 at 19 57 39_28c1e7be](https://github.com/user-attachments/assets/3aed65a4-a39d-446e-ab10-fcbc250b8e91)
![WhatsApp Image 2024-08-05 at 19 57 39_5e4d0d41](https://github.com/user-attachments/assets/e0e42941-6702-4dd9-92e6-f78114817e93)

## 3. Receiver Board
This receiver board is similar to the transmitter board. The difference is that the receiver board uses an LC parallel connection to minimize its impedance and behave like a purely resistive circuit.
### Schematic
![image](https://github.com/user-attachments/assets/2c330e94-dde6-4040-9238-a193823ad59b)

### Layout
![image](https://github.com/user-attachments/assets/65b319f4-6d3f-4dfa-a713-ed7fb8168611)

### Board Image
![image](https://github.com/user-attachments/assets/006d41a9-be1b-40c8-a733-dd52c77ccb6c)
![WhatsApp Image 2024-08-05 at 20 37 52_3ca948d0](https://github.com/user-attachments/assets/817a9dc8-1bd0-4250-a17a-59a39f7d4186)
![WhatsApp Image 2024-08-05 at 19 57 38_17e0c154](https://github.com/user-attachments/assets/29eada58-9809-4b87-b4fb-f76310aa7643)

Do contact me if you have some question or want to colaborate with me.
