#include <SoftwareSerial.h> 
#include <Servo.h> 
Servo myservo; 
int bluetoothTx = 10; // bluetooth tx to 10 pin
int bluetoothRx = 11; // bluetooth rx to 11 pin
int pushButton = 2;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  myservo.attach(9); // attach servo signal wire to pin 9
  //Setup usb serial connection to computer
  Serial.begin(9600);
  pinMode(pushButton, INPUT);

  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
}

void loop()
{
  if(bluetooth.available()> 0 ) // receive number from bluetooth
  {
    int servopos = bluetooth.read(); // save the received number to servopos
    Serial.println(servopos); // serial print servopos current number received from bluetooth
    myservo.write(servopos); // rotate the servo the angle received from the android app
   }
    int buttonState = digitalRead(pushButton);
    Serial.println(buttonState);
    delay(1000);  
  }
