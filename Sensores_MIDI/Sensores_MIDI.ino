#include <frequencyToNote.h>
#include <MIDIUSB.h>
#include <MIDIUSB_Defs.h>
#include <pitchToFrequency.h>
#include <pitchToNote.h>

#include <Wire.h>
#include <VL53L0X.h>

#define CANAIS 12 // numero de canais


//#include <Keyboard.h>

VL53L0X s1;
VL53L0X s2;
VL53L0X s3;
VL53L0X s4;
VL53L0X s5;
VL53L0X s6;
VL53L0X s7;
VL53L0X s8;
VL53L0X s9;
VL53L0X s10;
VL53L0X s11;
VL53L0X s12;


//Portas onde estão conectados os sensores.
#define port1 5
#define port2 6 
#define port3 7
#define port4 A3
#define port5 A4
#define port6 A5
#define port7 11
#define port8 12
#define port9 13
#define port10 A0
#define port11 A1
#define port12 A2
 
//Variaveis de valores

int valores[CANAIS] = {0,0,0,0,0,0,0,0,0,0,0,0};


void setup()
{

  
    
  pinMode(port1, OUTPUT);
  pinMode(port2, OUTPUT);
  pinMode(port3, OUTPUT);
  pinMode(port4, OUTPUT);
  pinMode(port5, OUTPUT);
  pinMode(port6, OUTPUT);
  pinMode(port7, OUTPUT);
  pinMode(port8, OUTPUT);
  pinMode(port9, OUTPUT);
  pinMode(port10, OUTPUT);
  pinMode(port11, OUTPUT);
  pinMode(port12, OUTPUT);

  digitalWrite(port1, LOW);
  digitalWrite(port2, LOW);
  digitalWrite(port3, LOW);
  digitalWrite(port4, LOW);
  digitalWrite(port5, LOW);
  digitalWrite(port6, LOW);
  digitalWrite(port7, LOW);
  digitalWrite(port8, LOW);
  digitalWrite(port9, LOW);
  digitalWrite(port10, LOW);
  digitalWrite(port11, LOW);
  digitalWrite(port12, LOW);

  delay(500);
  Wire.begin();
  Serial.begin(115200);
  
  digitalWrite(port1, HIGH);
  delay(150);
  s1.init(true);
  delay(100);
  s1.setAddress((uint8_t)40);

  digitalWrite(port2, HIGH);
  delay(150);
  s2.init(true);
  delay(100);
  s2.setAddress((uint8_t)42);
  
  digitalWrite(port3, HIGH);
  delay(150);
  s3.init(true);
  delay(100);
  s3.setAddress((uint8_t)43);
  
  digitalWrite(port4, HIGH);
  delay(150);
  s4.init(true);
  delay(100);
  s4.setAddress((uint8_t)44);
  
  digitalWrite(port5, HIGH);
  delay(150);
  s5.init(true);
  delay(100);
  s5.setAddress((uint8_t)45);
  
  digitalWrite(port6, HIGH);
  delay(150);
  s6.init(true);
  delay(100);
  s6.setAddress((uint8_t)46);

  digitalWrite(port7, HIGH);
  delay(150);
  s7.init(true);
  delay(100);
  s7.setAddress((uint8_t)47);

  digitalWrite(port8, HIGH);
  delay(150);
  s8.init(true);
  delay(100);
  s8.setAddress((uint8_t)48);

  digitalWrite(port9, HIGH);
  delay(150);
  s9.init(true);
  delay(100);
  s9.setAddress((uint8_t)49);

  digitalWrite(port10, HIGH);
  delay(150);
  s10.init(true);
  delay(100);
  s10.setAddress((uint8_t)50);
  
  digitalWrite(port11, HIGH);
  delay(150);
  s11.init(true);
  delay(100);
  s11.setAddress((uint8_t)51);

  digitalWrite(port12, HIGH);
  delay(150);
  s12.init(true);
  delay(100);
  s12.setAddress((uint8_t)52);

  //Serial.println("addresses set");

  delay(500);

   // Perfil de longo alcance
  s1.setSignalRateLimit(0.1);
  s1.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  s1.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);

  s2.setSignalRateLimit(0.1);
  s2.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  s2.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);

  s3.setSignalRateLimit(0.1);
  s3.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  s3.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14); 


  s4.setSignalRateLimit(0.1);
  s4.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  s4.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);


  s5.setSignalRateLimit(0.1);
  s5.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  s5.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);


  s6.setSignalRateLimit(0.1);
  s6.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  s6.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);

   
  s7.setSignalRateLimit(0.1);
  s7.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  s7.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);

  s8.setSignalRateLimit(0.1);
  s8.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  s8.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);

  s9.setSignalRateLimit(0.1);
  s9.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  s9.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14); 


  s10.setSignalRateLimit(0.1);
  s10.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  s10.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);


  s11.setSignalRateLimit(0.1);
  s11.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  s11.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);


  s12.setSignalRateLimit(0.1);
  s12.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  s12.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);

s1.startContinuous();
s2.startContinuous();
s3.startContinuous();
s4.startContinuous();
s5.startContinuous();
s6.startContinuous();
s7.startContinuous();
s8.startContinuous();
s9.startContinuous();
s10.startContinuous();
s11.startContinuous();
s12.startContinuous();

}

void loop()
{
  
  valores[0]=s1.readRangeContinuousMillimeters();
  valores[1]=s2.readRangeContinuousMillimeters();
  valores[2]=s3.readRangeContinuousMillimeters();
  valores[3]=s4.readRangeContinuousMillimeters();
  valores[4]=s5.readRangeContinuousMillimeters();
  valores[5]=s6.readRangeContinuousMillimeters();
  valores[6]=s7.readRangeContinuousMillimeters();
  valores[7]=s8.readRangeContinuousMillimeters();
  valores[8]=s9.readRangeContinuousMillimeters();
  valores[9]=s10.readRangeContinuousMillimeters();
  valores[10]=s11.readRangeContinuousMillimeters();
  valores[11]=s12.readRangeContinuousMillimeters();

/*
   //Serial.print("Valor A: ");
  Serial.print(a);
  Serial.println(" ");
  Serial.print("Valor B: ");
  Serial.print(b);
  Serial.println(" ");
  Serial.print("Valor C: ");
  Serial.print(c);
  Serial.println(" ");
  Serial.print("Valor D: ");
  Serial.print(d);
  Serial.println(" ");
  Serial.print("Valor E: ");
  Serial.print(e);
  Serial.println(" ");
  Serial.print("Valor F: ");
  Serial.print(f);
  Serial.println(" ");
  Serial.print("Valor G: ");
  Serial.print(g);
  Serial.println(" ");
  Serial.print("Valor H: ");
  Serial.print(h);
  Serial.println(" ");
  Serial.print("Valor I: ");
  Serial.print(i);
  Serial.println(" ");
  Serial.print("Valor J: ");
  Serial.print(j);
  Serial.println(" ");
  Serial.print("Valor K: ");
  Serial.print(k);
  Serial.println(" ");
  Serial.print("Valor L: ");
  Serial.print(l);
  Serial.println(" ");
*/
  /*
  //----------- Sensor 1
      if(a > 0  && a <= 500){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('A'); // Mudar tecla a ser pressionada 
        delay(50);
      }
        if(a > 500 && a <= 1000){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('W'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(a > 1000 && a <= 1500){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('S'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(a > 1500 && a <= 2000){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('E'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(a > 2000){ // Mudar aqui para alterar a distância das teclas
        delay(50);
      }
       //----------- Sensor 2
      if(b > 0  && b <= 500){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('D'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(b > 500 && b <= 1000){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('T'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(b > 1000 && b <= 1500){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('Y'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(b > 1500 && b <= 2000){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('U'); // Mudar tecla a ser pressionada
        delay(50);
      }
       if(b > 2000){ // Mudar aqui para alterar a distância das teclas
        delay(50);
      }
      //----------- Sensor 3
      if(c > 0  && c <= 500){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('O'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(c > 500 && c <= 1000){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('F'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(c > 1000 && c <= 1500){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('G'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(c > 1500 && c <= 2000){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('H'); // Mudar tecla a ser pressionada
        delay(50);
      }
       if(c > 2000){ // Mudar aqui para alterar a distância das teclas
        delay(50);
      }
       //----------- Sensor 4
      if(d > 0  && d <= 500){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('J'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(d > 500 && d <= 1000){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('K'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(d > 1000 && d <= 1500){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('L'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(d > 1500 && d <= 2000){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('A'); // Mudar tecla a ser pressionada
        delay(50);
      }
       if(d > 2000){ // Mudar aqui para alterar a distância das teclas
        delay(50);
      }
      //----------- Sensor 5
      if(e > 0  && e <= 500){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('W'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(e > 500 && e <= 1000){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('S'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(e > 1000 && e <= 1500){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('E'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(e > 1500 && e <= 2000){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('D'); // Mudar tecla a ser pressionada
        delay(50);
      }
       if(e > 2000){ // Mudar aqui para alterar a distância das teclas
        delay(50);
      }
      //----------- Sensor 6
      if(f > 0  && f <= 500){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('L'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(f > 500 && f <= 1000){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('K'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(f > 1000 && f <= 1500){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('J'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(f > 1500 && f <= 2000){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('H'); // Mudar tecla a ser pressionada
        delay(50);
      }
       if(f > 2000){ // Mudar aqui para alterar a distância das teclas
        delay(50);
      }
      //----------- Sensor 7
      if(g > 0  && g <= 500){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('U'); // Mudar tecla a ser pressionada 
        delay(50);
      }
        if(g > 500 && g <= 1000){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('O'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(g > 1000 && g <= 1500){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('F'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(g > 1500 && g <= 2000){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('G'); // Mudar tecla a ser pressionada
        delay(50);
      }
       if(g > 2000){ // Mudar aqui para alterar a distância das teclas
        delay(50);
      }
       //----------- Sensor 8
      if(h > 0  && h <= 500){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('Y'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(h > 500 && h <= 1000){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('T'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(h > 1000 && h <= 1500){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('D'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(h > 1500 && h <= 2000){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('E'); // Mudar tecla a ser pressionada
        delay(50);
      }
       if(h > 2000){ // Mudar aqui para alterar a distância das teclas
        delay(50);
      }
      //----------- Sensor 9
      if(i > 0  && i <= 500){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('Y'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(i > 500 && i <= 1000){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('H'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(i > 1000 && i <= 1500){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('J'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(i > 1500 && i <= 2000){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('S'); // Mudar tecla a ser pressionada
        delay(50);
      }
       if(i > 2000){ // Mudar aqui para alterar a distância das teclas
        delay(50);
      }
       //----------- Sensor 10
      if(j > 0  && j <= 500){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('K'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(j > 500 && j <= 1000){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('L'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(j > 1000 && j <= 1500){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('O'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(j > 1500 && j <= 2000){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('D'); // Mudar tecla a ser pressionada
        delay(50);
      }
       if(j > 2000){ // Mudar aqui para alterar a distância das teclas
        delay(50);
      }
      //----------- Sensor 11
      if(k > 0  && k <= 500){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('E'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(k > 500 && k <= 1000){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('D'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(k > 1000 && k <= 1500){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('O'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(k > 1500 && k <= 2000){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('G'); // Mudar tecla a ser pressionada
        delay(50);
      }
       if(k > 2000){ // Mudar aqui para alterar a distância das teclas
        delay(50);
      }
      //----------- Sensor 12
      if(l > 0  && l <= 500){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('U'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(l > 500 && l <= 1000){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('K'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(l > 1000 && l <= 1500){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('W'); // Mudar tecla a ser pressionada
        delay(50);
      }
        if(l > 1500 && l <= 2000){ // Mudar aqui para alterar a distância das teclas
        Keyboard.write('A'); // Mudar tecla a ser pressionada
        delay(50);
      }
       if(l > 2000){ // Mudar aqui para alterar a distância das teclas
        delay(50);
      }
*/

      for(int i = 0; i<CANAIS; i++){

        valores[i] = map(valores[i],0,2000,0,127);
        valores[i] = constrain(valores[i],0,127);

        //Serial.print(valores[i]);

        noteOn(i, valores[i], 64);   // Channel 0, middle C, normal velocity
        MidiUSB.flush();
        delay(20);
      }
      //Serial.println();

      
//delay(100);

}

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}
