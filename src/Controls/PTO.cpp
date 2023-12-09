#include "robotconfig.h"

// bool driveEnabled() {
//     if(controllerX != 0 && controllerY != 0) {
//         return true;
//     }
//     return false;
// }

// bool driveEnabled() {
//     if(controllerX != 0 && controllerY != 0) {
//         return true;
//     }
//     return false;
// }

void PTOToggle() {
    bool isPressed = false;
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
        if(!isPressed) {
            PTOEnabled = !PTOEnabled;
            isPressed = true;
        }
    }
    else {
        isPressed = false;
    }

    // if(driveEnabled() && )
}