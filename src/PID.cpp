#include "PID.h"
#include <vector>
/*
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
this->Kp = Kp_;
this->Ki = Ki_;
this->Kd = Kd_;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */

this->i_error += cte;
this->d_error = cte - this->p_error;
this->p_error = cte;
this->err += cte*cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return this->Kp*this->p_error + this->Ki*this->i_error + this->Kd*this->d_error;;  // TODO: Add your total error calc here!
}