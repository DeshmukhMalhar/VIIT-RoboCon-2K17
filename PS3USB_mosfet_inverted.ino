/*
  Example sketch for the PS3 USB library - developed by Kristian Lauszus
  For more information visit my blog: http://blog.tkjelectronics.dk/ or
  send me an e-mail:  kristianl@tkjelectronics.com
*/

#include <PS3USB.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#include <SPI.h>
#endif

USB Usb;
/* You can create the instance of the class in two ways */
PS3USB PS3(&Usb); // This will just create the instance
//PS3USB PS3(&Usb,0x00,0x15,0x83,0x3D,0x0A,0x57); // This will also store the bluetooth address - this can be obtained from the dongle when running the sketch

bool printAngle;
uint8_t state = 0;

void setup() {
  Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 USB Library Started"));
}

#define pwmPin  9
#define dirPin  8
int val = 0 , drive;
void loop() {
  Serial.print("Speed : ");
  Serial.println(drive);
  Usb.Task();

  if (PS3.PS3Connected || PS3.PS3NavigationConnected) {
    if (PS3.getAnalogHat(LeftHatX) > 137 || PS3.getAnalogHat(LeftHatX) < 117 || PS3.getAnalogHat(LeftHatY) > 137 || PS3.getAnalogHat(LeftHatY) < 117 ) {

      val = PS3.getAnalogHat(LeftHatX);
      if (val <= 120) {
        drive = map(val, 125, 0, 128, 230);
        analogWrite(pwmPin, drive);
        //Call direction functions here - Malhar
        digitalWrite(dirPin, LOW);

        Serial.println("                                                                        Backward");
      }
      else if ( val >= 132 ) {
        drive = map(val, 128, 255, 126, 25);
        analogWrite(pwmPin, drive);
        digitalWrite(dirPin, HIGH);

        Serial.println("                                                                       Forward");
      }
    }
    else
    {
      drive = 255;
      digitalWrite(dirPin, HIGH);
      Serial.println("STOP !");
    }
  }


}
