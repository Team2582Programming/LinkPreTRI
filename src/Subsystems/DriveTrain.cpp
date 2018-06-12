// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "../Commands/JoyDrive.h"
#include "DriveTrain.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    rightFront = RobotMap::driveTrainRightFront;
    rightBack = RobotMap::driveTrainRightBack;
    rightMotors = RobotMap::driveTrainRightMotors;
    rightEncoder = RobotMap::driveTrainRightEncoder;
    rightSide = RobotMap::driveTrainRightSide;
    leftFront = RobotMap::driveTrainLeftFront;
    leftBack = RobotMap::driveTrainLeftBack;
    leftMotors = RobotMap::driveTrainLeftMotors;
    leftEncoder = RobotMap::driveTrainLeftEncoder;
    leftSide = RobotMap::driveTrainLeftSide;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    drive_x = 0;
    drive_y = 0;

    //bgyro = RobotMap::driveTrainGyro;

    power = .5;
    kP = .02;
    autoTime = 2.150;
    delay = .000;

    turnAngle = -60;
    pos = false;
    SwitchPos = "";
    ultraVal = 80;
}

void DriveTrain::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new JoyDrive());
}

void DriveTrain::Periodic() {
    // Put code here to be run every loop

}

void DriveTrain::JoystickDrive(std::shared_ptr<frc::Joystick> joy)
{
	drive_x = joy->GetX();
	drive_y = joy->GetY();
	leftMotors->Set(pow(drive_x, 3) + pow(-drive_y, 3));
	rightMotors->Set(pow(drive_x, 3) + pow(drive_y, 3));
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::AutoDrive(){
	leftMotors->Set(.5);
	rightMotors->Set(-.5);
}

void DriveTrain::StopDrive(){
	leftMotors->Set(0);
	rightMotors->Set(0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// gyro functions start here

double DriveTrain::GetPower() {
	power = frc::SmartDashboard::GetNumber("GyroPower", power);
	return power;
}

double DriveTrain::GetkP() {
	kP = frc::SmartDashboard::GetNumber("kP", kP);
	return kP;
}

double DriveTrain::GetDelay() {
	delay = frc::SmartDashboard::GetNumber("AutoDelay", delay);
	return delay;
}

std::string DriveTrain::GetDirection() {
	SwitchPos = frc::SmartDashboard::GetString("Switch is", SwitchPos);
	return SwitchPos;
}

double DriveTrain::TurnAngle() {
	turnAngle = frc::SmartDashboard::GetNumber("Turn Angle", turnAngle);
	return turnAngle;
}

double DriveTrain::DisplayAngle() {
	return gyro->GetAngle();
}

void DriveTrain::ResetGyro() {
	gyro->Reset();
}

/* double DriveTrain::getDistance() {

} */

bool DriveTrain::GetPos() {
	return pos;
}

double DriveTrain::getAutoTime() {
	autoTime = frc::SmartDashboard::GetNumber("AutoTime", autoTime);
	return autoTime;
}

void DriveTrain::AutoGyroDrive(double speed, double correction) {
	double angle = gyro->GetAngle();
	double idealAngle = 0;
	leftMotors->Set(pow(speed, (idealAngle - angle) * -correction));
	rightMotors->Set(pow(speed, (idealAngle - angle) * -correction));
}

void DriveTrain::TurnFun(std::string Direction, double TurnAngle) {
	if (Direction == "L")
	{
		// robotDrive->TankDrive(-.3,.3);
		pos = true;
	}
	else if (Direction == "R")
	{
		double angle = gyro->GetAngle();
		if (TurnAngle > 0 )
		{
			double angle = gyro->GetAngle();
			if (angle - TurnAngle >= 0)
			{
				//robotDrive->TankDrive(0,0);
				pos = true;
			}
			else {
				//robotDrive->TankDrive(.6,-.6);
				pos = false;
			}
		}
		else if (TurnAngle < 0) {
			double angle = gyro->GetAngle();
			if (TurnAngle - angle >= 0) {
				//robotDrive->TankDrive(0,0);
				pos = true;
			}
			else
			{
				//robotDrive->TankDrive(-.6, .6);
				pos = false;
			}
		}

		}
}

double DriveTrain::GetUltraVal() {
	ultraVal = frc::SmartDashboard::GetNumber("UltraVal", ultraVal);
	return ultraVal;
}

void DriveTrain::Backwards(double speed, double correction) {
	double angle = gyro->GetAngle();
	double idealAngle = 0;
	leftMotors->Set(pow(speed, (idealAngle - angle) * correction));
	rightMotors->Set(pow(speed, (idealAngle - angle) * correction));
}

std::string DriveTrain::GetSide()
{
	SwitchPos = SmartDashboard::GetString("Side is", SwitchPos);
	return SwitchPos;
}
