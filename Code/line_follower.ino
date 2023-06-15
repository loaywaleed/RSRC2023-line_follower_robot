#define ir1   A0
#define ir2   A1
#define ir3   A2
#define ir4   A3
#define ir5   A4

# define Trig 2
# define Echo 4

# define enable_left 5
# define motor_left1 7        
# define motor_left2 8

# define enable_right 6
# define motor_right1 9        
# define motor_right2 10

void forward();
void left();
void right();
void stop();
void motor_speed(int percent1, int percent2);


float motor_calib = 0.7;

void setup() {
 
pinMode(enable_left,OUTPUT);   
pinMode(motor_left1,OUTPUT);  
pinMode(motor_left2,OUTPUT);  

pinMode(enable_right,OUTPUT);   
pinMode(motor_right1,OUTPUT);   
pinMode(motor_right2,OUTPUT);


}

void loop() {

  if((digitalRead(ir1)==0)&&(digitalRead(ir2)==0)&&(digitalRead(ir3)==1)&&(digitalRead(ir4)==0)&&(digitalRead(ir5)==0))
  {
    motor_speed(100, 100);
  }
  else if((digitalRead(ir1)==0)&&(digitalRead(ir2)==1)&&(digitalRead(ir3)==1)&&(digitalRead(ir4)==1)&&(digitalRead(ir5)==0))
  {
    motor_speed(100, 100);
  }
  else if((digitalRead(ir1)==0)&&(digitalRead(ir2)==1)&&(digitalRead(ir3)==1)&&(digitalRead(ir4)==0)&&(digitalRead(ir5)==0))
  {
    motor_speed(70, 100);
  }
  else if((digitalRead(ir1)==0)&&(digitalRead(ir2)==0)&&(digitalRead(ir3)==1)&&(digitalRead(ir4)==1)&&(digitalRead(ir5)==0))
  {
    motor_speed(100, 70);
  }
  else if((digitalRead(ir1)==0)&&(digitalRead(ir2)==1)&&(digitalRead(ir3)==1)&&(digitalRead(ir4)==1)&&(digitalRead(ir5)==0))
  {
    motor_speed(100, 100);
  }
  else if((digitalRead(ir1)==0)&&(digitalRead(ir2)==0)&&(digitalRead(ir3)==0)&&(digitalRead(ir4)==1)&&(digitalRead(ir5)==1))
  {
    motor_speed(100, 30);
  }
  else if((digitalRead(ir1)==1)&&(digitalRead(ir2)==0)&&(digitalRead(ir3)==0)&&(digitalRead(ir4)==0)&&(digitalRead(ir5)==0))
  {
    motor_speed(0, 100);
  }
  else if((digitalRead(ir1)==0)&&(digitalRead(ir2)==0)&&(digitalRead(ir3)==0)&&(digitalRead(ir4)==0)&&(digitalRead(ir5)==1))
  {
    motor_speed(100, 0);
  }
  else if ((digitalRead(ir1)==1)&&(digitalRead(ir2)==1)&&(digitalRead(ir3)==1)&&(digitalRead(ir4)==1)&&(digitalRead(ir5)==1))
  {
    motor_speed(0, 0);
  }
  else
  {}
}



void motor_speed(int percent1, int percent2)
{
  int max = 220;
  analogWrite(enable_left, max * (percent1/100.0) * motor_calib);
  analogWrite(enable_right, 240 * (percent2/100.0));
  digitalWrite (motor_left1,0);
  digitalWrite (motor_left2,1);
  digitalWrite (motor_right1,0);
  digitalWrite (motor_right2,1);

}




