int LEDC_CHANNEL_12 = 12;
int LEDC_NUM_12;
int LEDC_CHANNEL_13 = 13;
int LEDC_NUM_13;
int LEDC_CHANNEL_14 = 14;
int LEDC_NUM_14;
int LEDC_CHANNEL_15 = 15;
int LEDC_NUM_15;

int speed;

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
void forwards_Q(int number){
  for(int i = 0; i < number / 25; i++){
    motor_Q_Q_Q_Q(0, speed, 0, speed);
    delay((.625) * 1000);
    motor_Q_Q_Q_Q(0, 0, 0, speed);
    delay((0.065625) * 1000);
  }
  motor_Q_Q_Q_Q(0, 0, 0, 0);
}
void forward25(){
  for(int i2 = 0; i2 < 1; i2++){
    motor_Q_Q_Q_Q(0, speed, 0, speed);
    delay((.625) * 1000);
    motor_Q_Q_Q_Q(0, 0, 0, speed);
    delay((0.065625) * 1000);
  }
  motor_Q_Q_Q_Q(0, 0, 0, 0);
}
void backward25(){
  for(int i3 = 0; i3 < 1; i3++){
    motor_Q_Q_Q_Q(speed, 0, speed, 0);
    delay((.625) * 1000);
    motor_Q_Q_Q_Q(0, speed, 0, 0);
    delay((0.065625) * 1000);
  }
  motor_Q_Q_Q_Q(0, 0, 0, 0);
}
void turnleft(){
  for(int i4 = 0; i4 < 1; i4++){
    motor_Q_Q_Q_Q(0, 0, 0, speed);
    // 0.253125
    // 0.28125
    delay((0.325) * 1000);
  }
  motor_Q_Q_Q_Q(0, 0, 0, 0);
}
void forward50(){
  for(int i5 = 0; i5 < 2; i5++){
    motor_Q_Q_Q_Q(0, speed, 0, speed);
    delay((.625) * 1000);
    motor_Q_Q_Q_Q(0, 0, 0, speed);
    delay((0.065625) * 1000);
  }
  motor_Q_Q_Q_Q(0, 0, 0, 0);
}
void backward50(){
  for(int i6 = 0; i6 < 2; i6++){
    motor_Q_Q_Q_Q(speed, 0, speed, 0);
    delay((.625) * 1000);
    motor_Q_Q_Q_Q(0, speed, 0, 0);
    delay((0.065625) * 1000);
  }
  motor_Q_Q_Q_Q(0, 0, 0, 0);
}
void turnright(){
  for(int i7 = 0; i7 < 1; i7++){
    motor_Q_Q_Q_Q(0, speed, 0, 0);
    // 0.253125
    // 0.28125
    delay((0.325) * 1000);
  }
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
  pinMode(18, INPUT);
  speed = 300;
  while (!(digitalRead(18) == 0));
  forward50();
  turnleft();
}

void loop() {
}