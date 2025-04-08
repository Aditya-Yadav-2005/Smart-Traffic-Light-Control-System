// Define the pin numbers for each color of the traffic lights on 4 different lanes
int redPins[] = {2, 5, 8, 11};    // Red lights for lanes 1, 2, 3, and 4
int yellowPins[] = {3, 6, 9, 12}; // Yellow lights for lanes 1, 2, 3, and 4
int greenPins[] = {4, 7, 10, 13};  // Green lights for lanes 1, 2, 3, and 4

// Define the duration (in milliseconds) for each light color
const unsigned long greenTime = 7000;  // Green light stays on for 7 seconds
const unsigned long yellowTime = 3000; // Yellow light stays on for 3 seconds
const unsigned long redTime = 7000;    // Red light stays on for 7 seconds (though not directly used in the code)

void setup() {
  // Set up all the traffic light pins as OUTPUT pins so we can control them
  for (int i = 0; i < 4; i++) {
    pinMode(redPins[i], OUTPUT);      // Set the pin for the red light as an output
    pinMode(yellowPins[i], OUTPUT);   // Set the pin for the yellow light as an output
    pinMode(greenPins[i], OUTPUT);    // Set the pin for the green light as an output
  }
}

void loop() {
  // Loop through all the lanes and control the traffic lights for each lane
  for (int i = 0; i < 4; i++) {
    controlTraffic(i);  // Call the function to control traffic for each lane, one by one
  }
}

void controlTraffic(int greenLaneIndex) {
  // This function controls the traffic lights for one lane at a time
  // 'greenLaneIndex' determines which lane gets the green light
  
  for (int i = 0; i < 4; i++) {
    if (i == greenLaneIndex) {
      // Turn the green light ON for the selected lane, and turn off the red light
      digitalWrite(greenPins[i], HIGH);  
      digitalWrite(redPins[i], LOW);   
    } else {
      // For all other lanes, turn the red light ON and green light OFF
      digitalWrite(redPins[i], HIGH);  
      digitalWrite(greenPins[i], LOW); 
    }
    // Turn off the yellow light for all lanes during green or red phases
    digitalWrite(yellowPins[i], LOW);  
  }
  
  // Keep the green light ON for the selected lane for the set green time (7 seconds)
  delay(greenTime);

  // After green time, switch the green light off and turn the yellow light ON
  digitalWrite(greenPins[greenLaneIndex], LOW);
  digitalWrite(yellowPins[greenLaneIndex], HIGH); 

  // Keep the yellow light ON for the selected lane for the set yellow time (3 seconds)
  delay(yellowTime);

  // After the yellow time, turn the yellow light off and keep the red light ON
  digitalWrite(yellowPins[greenLaneIndex], LOW);
  digitalWrite(redPins[greenLaneIndex], LOW);  // Red light is OFF here since all lanes are processed one by one
} 
