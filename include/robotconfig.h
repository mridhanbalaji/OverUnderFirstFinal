#include "main.h"

extern pros::Controller master;

extern pros::Motor left_front_motor; // port 1, not reversed
extern pros::Motor left_back_motor; // port 2, not reversed
extern pros::Motor left_PTO_motor; // port 4, reversed
extern pros::Motor right_front_motor; // port 3, reversed
extern pros::Motor right_back_motor; // port 4, reversed
extern pros::Motor right_PTO_motor; // port 3, reversed
extern pros::Motor Intakemotor; // port 3, reversed

// Create a motor object on port 17, with a purple cart, set as reversed, and
// with motor_speed_controller as a custom velocity controller
extern sylib::Motor flywheel;
 
extern sylib::SpeedControllerInfo flywheelController;

// drivetrain motor groups
extern pros::MotorGroup left_side_motors;
extern pros::MotorGroup right_side_motors;

extern bool PTOEnabled;
extern int controllerX;
extern int controllerY;