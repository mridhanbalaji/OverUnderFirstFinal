#include "robotconfig.h"
#include "pros/motors.h"


const double varE
 = 2.718281828459045;

pros::Controller master(pros::E_CONTROLLER_MASTER);


pros::Motor left_front_motor(1,pros::E_MOTOR_GEAR_600, true); // port 2, not reversed
pros::Motor left_back_motor(2,pros::E_MOTOR_GEAR_600, false); // port 1, not reversed
pros::Motor left_PTO_motor(3,pros::E_MOTOR_GEAR_600, false); // port 2, not reversed
pros::Motor right_front_motor(8,pros::E_MOTOR_GEAR_600, true); // port 3, reversed
pros::Motor right_back_motor(9,pros::E_MOTOR_GEAR_600, false); // port 4, reversed.
pros::Motor right_PTO_motor(10,pros::E_MOTOR_GEAR_600, false); // port 4, reversed.
pros::Motor Intakemotor(12,pros::E_MOTOR_GEAR_600,true); // port 3, reversed
// pros::Motor flywheel(14,pros::E_MOTOR_GEAR_600,true); // port 3, reversed
 
 
// drivetrain motor groups
pros::MotorGroup left_side_motors({left_front_motor, left_back_motor, left_PTO_motor});
pros::MotorGroup right_side_motors({right_front_motor, right_back_motor, right_PTO_motor});



sylib::SpeedControllerInfo flywheelController(
    [](double rpm) {
      return std::pow(varE, (-0.001 * rpm * 3600 / 3600 + 1)) + 3.065;
    },     // kV function
    10,    // kP
    0.001, // kI00097
    0,     // kD
    0,     // kH
    true,  // anti-windup enabled
    50,    // anti-windup range
    true,  // p controller bounds threshold enabled
    50,    // p controller bounds cutoff enabled
    0.01,  // kP2 for when over threshold
    50,    // range to target to apply max voltage
    false, // coast down enabled
    0,     // coast down theshhold
    1     // coast down constant
);

// Create a motor object on port 17, with a purple cart, set as reversed, and
// with motor_speed_controller as a custom velocity controller
sylib::Motor flywheel(1, 3600, true, flywheelController);
