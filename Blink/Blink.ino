//This is my first commit comment
//Include ros library
#include <ros.h>
//Include message class
#include <std_msgs/Empty.h>

//Create The NodeHandle to access functions
ros::NodeHandle  nh;
// Define the callback function
void messageCb( const std_msgs::Empty& toggle_msg){
  digitalWrite(13, HIGH-digitalRead(13));   // blink the led
}
//Create Subscriber Object
//ros::Subscriber<Message_type> object_name("topic_name", &callback_function_name);
ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageCb);

void setup()
{ 
  pinMode(13, OUTPUT);
  //Initialize Node
  nh.initNode();
  //Declare that this Node is a subscriber Node
  //nh.subscribe(subscriber_object_name);
  nh.subscribe(sub);
  Serial.begin(9600);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}
