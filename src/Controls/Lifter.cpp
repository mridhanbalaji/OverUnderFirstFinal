#include "robotconfig.h"

void Lifter::lift() {
  int volts = 0;
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && !master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
    volts = -127;
    }
  else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && !master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    volts = 127;
  }
  else {
    volts = 0;
  }
  
  if(PTOEnabled) {
    right_PTO_motor.move(volts);
    left_PTO_motor.move(volts);
  }
}