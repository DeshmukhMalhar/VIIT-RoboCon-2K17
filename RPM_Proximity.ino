void setup() {
  pinMode(2, INPUT_PULLUP);
  Serial.begin(115200);
}
int flag = 0;
float rpm = 0.000000;
unsigned long duration = 0, duration1 = 0, duration0 = 0;
void loop() {
  if ((digitalRead(2) == LOW ) && (flag == 0)) {
    duration0 = millis();
    flag = 1;
  }
  if ((digitalRead(2) == LOW ) && (flag == 1)) {
    duration1 = millis();
    flag = 0;
  }
  duration = duration1 - duration0;
  rpm = 60000 / duration ;
  Serial.print("RPM : ");
  Serial.println(rpm);
}
