/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutonomousDeadDrive.h"
std::string gamedata = frc::DriverStation::GetInstance().GetGameSpecificMessage();
AutonomousDeadDrive::AutonomousDeadDrive(): frc::Command() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::driveTrain.get());
	Requires(Robot::intake.get());
	// eg. Requires(Robot::chassis.get());
	SetTimeout(2.050);
}

// Called just before this Command runs the first time
void AutonomousDeadDrive::Initialize() {


}

// Called repeatedly when this Command is scheduled to run
void AutonomousDeadDrive::Execute() {

	Robot::driveTrain->AutoDrive();
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousDeadDrive::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void AutonomousDeadDrive::End() {


	Robot::driveTrain->StopDrive();
	if(gamedata.length() > 0)
	{
	if(gamedata[0] == Robot::driveTrain->GetSide()[0])
	{
		Robot::intake->Spit();
		Wait(3);
		Robot::intake->StopIntake();
	}
	}
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousDeadDrive::Interrupted() {
	End();
}
