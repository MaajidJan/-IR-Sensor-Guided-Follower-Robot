// GitHub Repository: https://github.com/MaajidJan/your_repository
//
// Overview:
// This code controls a robot using an Arduino, L293D motor shield, servo motor, and IR sensors.
//
// Motor Connection:
// - Be careful while connecting motors to the L293D motor shield to avoid issues.
// - If a motor is connected to the wrong slot (e.g., Motor 4 to M3 but declared as M4 in the code), it will not move.
//
// Power Supply:
// - Use an external power supply above 7 volts to run the motors for optimal performance.
// - Motors will not function properly on the Arduino's 5V supply.
//
// Motor Testing:
// - Always test individual motors to verify their directions before integrating them into your robot.
//
// Troubleshooting:
// - If the IR sensors detect obstacles but the wheels do not move, check the motor connections and the code.
//
// Importance for Beginners:
// These steps are crucial, as beginners often overlook them and get stuck at these stages.
