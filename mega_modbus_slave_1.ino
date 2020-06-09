/*
 * Date: Fri, 15/05/2020
 * Desc: MEGA with 8-relay, Modbus Slave on serialPort1
 * Info: Initial state = all relays OFF
 */

#include <modbus.h>
#include <modbusDevice.h>
#include <modbusRegBank.h>
#include <modbusSlave.h>

modbusDevice regBank;
modbusSlave slave;

void setup()
{
  // initial delay
  delay(2000);     
  regBank.setId(13); ///Set Slave ID
  
  // Add Digital Output registers
  regBank.add(2);
  regBank.add(3);
  regBank.add(4);
  regBank.add(5);
  regBank.add(6);
  regBank.add(7); 
  regBank.add(8);
  regBank.add(9);
  regBank.add(10);
  regBank.add(11);
  regBank.add(12);
  regBank.add(13);
  
  slave._device = &regBank;  
  slave.setBaud(9600);
  // initialize regBank Digital Output
  regBank.set(2, (word)0xFF);
  regBank.set(3, (word)0xFF);  
  regBank.set(4, (word)0xFF);  
  regBank.set(5, (word)0xFF);  
  regBank.set(6, (word)0xFF);  
  regBank.set(7, (word)0xFF);  
  regBank.set(8, (word)0xFF);  
  regBank.set(9, (word)0xFF);  
  regBank.set(10, (word)0xFF);  
  regBank.set(11, (word)0xFF);  
  regBank.set(12, (word)0xFF);  
  regBank.set(13, (word)0xFF);     

  // initialize I/O
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);  
}
void loop(){                              
  //Digital output  
  int DO2 = regBank.get(2);
    if (DO2 <= 0 && digitalRead(2) == HIGH)digitalWrite(2,LOW);
    if (DO2 >= 1 && digitalRead(2) == LOW)digitalWrite(2,HIGH);
  int DO3 = regBank.get(3);
    if (DO3 <= 0 && digitalRead(3) == HIGH)digitalWrite(3,LOW);
    if (DO3 >= 1 && digitalRead(3) == LOW)digitalWrite(3,HIGH);
  int DO4 = regBank.get(4);
    if (DO4 <= 0 && digitalRead(4) == HIGH)digitalWrite(4,LOW);
    if (DO4 >= 1 && digitalRead(4) == LOW)digitalWrite(4,HIGH);
  int DO5 = regBank.get(5);
    if (DO5 <= 0 && digitalRead(5) == HIGH)digitalWrite(5,LOW);
    if (DO5 >= 1 && digitalRead(5) == LOW)digitalWrite(5,HIGH);
  int DO6 = regBank.get(6);
    if (DO6 <= 0 && digitalRead(6) == HIGH)digitalWrite(6,LOW);
    if (DO6 >= 1 && digitalRead(6) == LOW)digitalWrite(6,HIGH);
  int DO7 = regBank.get(7);
    if (DO7 <= 0 && digitalRead(7) == HIGH)digitalWrite(7,LOW);
    if (DO7 >= 1 && digitalRead(7) == LOW)digitalWrite(7,HIGH);
  int DO8 = regBank.get(8);
    if (DO8 <= 0 && digitalRead(8) == HIGH)digitalWrite(8,LOW);
    if (DO8 >= 1 && digitalRead(8) == LOW)digitalWrite(8,HIGH);
  int DO9 = regBank.get(9);
    if (DO9 <= 0 && digitalRead(9) == HIGH)digitalWrite(9,LOW);
    if (DO9 >= 1 && digitalRead(9) == LOW)digitalWrite(9,HIGH);
  int DO10 = regBank.get(10);
    if (DO10 <= 0 && digitalRead(10) == HIGH)digitalWrite(10,LOW);
    if (DO10 >= 1 && digitalRead(10) == LOW)digitalWrite(10,HIGH);
  int DO11 = regBank.get(11);
    if (DO11 <= 0 && digitalRead(11) == HIGH)digitalWrite(11,LOW);
    if (DO11 >= 1 && digitalRead(11) == LOW)digitalWrite(11,HIGH);
  int DO12 = regBank.get(12);
    if (DO12 <= 0 && digitalRead(12) == HIGH)digitalWrite(12,LOW);
    if (DO12 >= 1 && digitalRead(12) == LOW)digitalWrite(12,HIGH);
  int DO13 = regBank.get(13);
    if (DO13 <= 0 && digitalRead(13) == HIGH)digitalWrite(13,LOW);
    if (DO13 >= 1 && digitalRead(13) == LOW)digitalWrite(13,HIGH);

  // Run slave
  slave.run();  
}
