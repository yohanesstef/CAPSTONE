#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C oled(U8G2_R0);

#define CLK 4
#define DT  5
#define SW  6

struct{
  int a_prev, a_val;
  bool dir;
  int enc_count;
  unsigned long prev_tim;

  struct{
    bool now, prev;
    int count;
  }button;
}enc;

int analog;
int freq = 100;

void display_frequency(int num){
  char buf[20];
  oled.setFont(u8g2_font_ncenB12_tr);
  sprintf(buf,"f  : %d kHz",num);
  oled.clearBuffer();
  oled.drawStr(10, 20, buf);
  oled.sendBuffer();
}

void intro(){
  oled.clearBuffer();oled.drawStr(10, 15, "Capstone A3 Team");oled.sendBuffer();
  delay(1000);
  oled.clearBuffer();oled.drawStr(10, 15, "Capstone A3 Team.");oled.sendBuffer();
  delay(1000);
  oled.clearBuffer();oled.drawStr(10, 15, "Capstone A3 Team..");oled.sendBuffer();
  delay(1000);
  oled.clearBuffer();oled.drawStr(10, 15, "Capstone A3 Team...");oled.sendBuffer();
  delay(1000);
  oled.clearBuffer();oled.drawStr(15, 15, "Yohanes Dakita");oled.drawStr(30, 25, "Daffa Acha");oled.sendBuffer();
  delay(2000);
  oled.clearBuffer();oled.drawStr(10, 15, "Inverter Board from");oled.sendBuffer();
  delay(2000);
  oled.clearBuffer();oled.drawStr(15, 10, "Wireless Power");oled.drawStr(35, 20, "Transfer");oled.sendBuffer();
  delay(2000);
}

void setup() {
  //------------------OLED
  oled.begin();
  oled.setFlipMode(1);
  oled.clearBuffer();
  oled.setFont(u8g2_font_ncenB08_tr);

  // -----------------ENCODER
  pinMode(CLK,INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);
  enc.a_prev = digitalRead(CLK);
  enc.button.prev = digitalRead(SW);


  Serial.begin(9600);
  pinMode(9,1);
  pinMode(13,1);
  pinMode(A0,0);
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1A |= (1 <<WGM11) | (1 << COM1A1) | (1 << COM1B1);
  TCCR1B |= (1 << CS10) | (1 << WGM12) | (1 << WGM13);

  intro();
  // put your setup code here, to run once:

}

void loop() {
    enc.button.now = digitalRead(SW);
    if(enc.button.now != enc.button.prev) {
      enc.button.count++;
      Serial.print("Button: ");Serial.println(enc.button.count);
    }
    enc.button.prev = enc.button.now;     
    enc.a_val = digitalRead(CLK);
    if (enc.a_val != enc.a_prev){
      if(digitalRead(DT) != enc.a_val){
        enc.enc_count++;
        freq ++;
        if(freq>=200)freq = 200;
        enc.dir = true;
      }
      else if(digitalRead(DT) == enc.a_val){
        enc.enc_count--;
        freq--;
        if(freq<=80)freq = 80;
        enc.dir = false;
      }
      Serial.print("dir: ");Serial.println((enc.dir) ? "clock wise" : "counter clock wise");
      Serial.print("Count: ");Serial.println(enc.enc_count);
      enc.prev_tim = millis();
    }
    enc.a_prev = enc.a_val;
    // display_frequency(200 - freq + 80);

  // ICR1 = map(analogRead(A0),10,1023,80,200);
  // ICR1 = freq;
  OCR1A = ICR1 / 2;
  float hertz = 1 / ((float)ICR1/16000);
  // display_frequency(200 - ICR1 + 80);
  display_frequency(hertz);
}
