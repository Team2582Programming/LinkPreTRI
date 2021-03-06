// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ROBOTMAP_H
#define ROBOTMAP_H

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "WPILib.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static std::shared_ptr<frc::SpeedController> driveTrainRightFront;
	static std::shared_ptr<frc::SpeedController> driveTrainRightBack;
	static std::shared_ptr<frc::SpeedControllerGroup> driveTrainRightMotors;
	static std::shared_ptr<frc::Encoder> driveTrainRightEncoder;
	static std::shared_ptr<frc::PIDController> driveTrainRightSide;
	static std::shared_ptr<frc::SpeedController> driveTrainLeftFront;
	static std::shared_ptr<frc::SpeedController> driveTrainLeftBack;
	static std::shared_ptr<frc::SpeedControllerGroup> driveTrainLeftMotors;
	static std::shared_ptr<frc::Encoder> driveTrainLeftEncoder;
	static std::shared_ptr<frc::PIDController> driveTrainLeftSide;
	static std::shared_ptr<frc::SpeedController> intakeRollerRight;
	static std::shared_ptr<frc::SpeedController> intakeRollerLeft;
	static std::shared_ptr<frc::DigitalInput> intakeLaser;
	static std::shared_ptr<frc::SpeedController> climbCilmber;
	static std::shared_ptr<frc::SpeedController> blinkinBlinkin;
	static std::shared_ptr<frc::SpeedController> armArm;
	static std::shared_ptr<frc::SpeedController> pIDEleEle;
	static std::shared_ptr<frc::AnalogInput> pIDEleStringPot;
	static std::shared_ptr<frc::PIDController> pIDEleElevator;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	static std::shared_ptr<frc::SpeedController> climbClimber2;

	//This is the gyro being declared that we use on our Robots
	static std::shared_ptr<ADXRS450_Gyro> driveTrainGyro;

	static void init();
};
#endif
