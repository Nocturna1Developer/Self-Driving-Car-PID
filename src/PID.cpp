// CREDIT :

// https: //stackoverflow.com/questions/2868439 is-there-a-way-to-limit-an-integer-value-to-a-certain-range-without-branching,
// https://github.com/felipemartinezs/CarND-PID-Control-Project-master/blob/master/src/main.cpp (used as reference)// PID Controller lesson
// https://aip.scitation.org/doi/pdf/10.1063/1.4958613
// PID Implementation Solution code snippet

#include "PID.h"

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_)
{
    // TODO: Initialize PID coefficients (and errors, if needed)

    // Values found in the pid.h file

    /**
    * PID Errors
    */
    p_error, i_error, d_error = 0.0;

    /**
    * PID Coefficients
    */
    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;

    double cte = 0.0;
}

void PID::UpdateError(double cte)
{
    // TODO: Update PID errors based on cte.
  
	// CREDIT: PID Implementation Solution code snippet
 
    // Integral
    i_error += cte;

    // Differential
    double differential = cte - p_error;
    d_error = differential;
  
  	// Proportional
    p_error = cte;


}

double PID::TotalError()
{
    // TODO: Calculate and return the total error
    double total_p_error = - Kp * p_error;
    double total_i_error = Ki * i_error;
    double total_d_error = Kd * d_error;

    double total_error = total_p_error - total_i_error - total_d_error;

    return total_error; // TODO: Add your total error calc here!
}