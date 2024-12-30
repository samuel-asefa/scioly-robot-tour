// Language ArduinoC
int LEDC_CHANNEL_12 = 12;
int LEDC_NUM_12;
int LEDC_CHANNEL_13 = 13;
int LEDC_NUM_13;
int LEDC_CHANNEL_14 = 14;
int LEDC_NUM_14;
int LEDC_CHANNEL_15 = 15;
int LEDC_NUM_15;

int speed;

void turnright(){
  motor_Q_Q_Q_Q(0, speed, speed, 0);
  delay((0.175) * 1000);
  motor_Q_Q_Q_Q(0, 0, 0, 0);
}
void forward50(){
  for(int i = 0; i < 2; i++){
    motor_Q_Q_Q_Q(0, speed - 7, 0, speed);
    delay((0.875) * 1000);
  }
  motor_Q_Q_Q_Q(0, 0, 0, 0);
}
void forward25(){
  for(int i2 = 0; i2 < 1; i2++){
    motor_Q_Q_Q_Q(0, speed - 7, 0, speed);
    delay((0.875) * 1000);
  }
}
void LEDC_12(){
  if (LEDC_NUM_12 > 255){
    LEDC_NUM_12 = 255;
  }
  if (LEDC_NUM_12 < 0){
    LEDC_NUM_12 = 0;
  }
}
void LEDC_13(){
  if (LEDC_NUM_13 > 255){
    LEDC_NUM_13 = 255;
  }
  if (LEDC_NUM_13 < 0){
    LEDC_NUM_13 = 0;
  }
}
void LEDC_14(){
  if (LEDC_NUM_14 > 255){
    LEDC_NUM_14 = 255;
  }
  if (LEDC_NUM_14 < 0){
    LEDC_NUM_14 = 0;
  }
}
void LEDC_15(){
  if (LEDC_NUM_15 > 255){
    LEDC_NUM_15 = 255;
  }
  if (LEDC_NUM_15 < 0){
    LEDC_NUM_15 = 0;
  }
}
void motor_Q_Q_Q_Q(int L1, int L2, int R1, int R2){
  LEDC_NUM_12 = L1;
  LEDC_12();
  ledcWrite(12, (LEDC_NUM_12+1));
  LEDC_NUM_13 = L2;
  LEDC_13();
  ledcWrite(13, (LEDC_NUM_13+1));
  LEDC_NUM_14 = R1;
  LEDC_14();
  ledcWrite(14, (LEDC_NUM_14+1));
  LEDC_NUM_15 = R2;
  LEDC_15();
  ledcWrite(15, (LEDC_NUM_15+1));
}
void turnleft(){
  motor_Q_Q_Q_Q(speed, 1, 1, speed);
  delay((0.175) * 1000);
  motor_Q_Q_Q_Q(0, 0, 0, 0);
}

void setup() {
  ledcSetup(LEDC_CHANNEL_12, 5000, 8);
  ledcAttachPin(12, LEDC_CHANNEL_12);
  ledcSetup(LEDC_CHANNEL_13, 5000, 8);
  ledcAttachPin(13, LEDC_CHANNEL_13);
  ledcSetup(LEDC_CHANNEL_14, 5000, 8);
  ledcAttachPin(14, LEDC_CHANNEL_14);
  ledcSetup(LEDC_CHANNEL_15, 5000, 8);
  ledcAttachPin(15, LEDC_CHANNEL_15);
  pinMode(18, OUTPUT);
  speed = 200;
  while (!(digitalRead(36) == 0));
  forward25();
  forward50();
  forward50();
  forward50();
  forward50();
  forward50();
}

void loop() {
}