# Automated-Traffic-Control-System-using-Embedded-C-RTOS

This project implements an Automated Traffic Control System using the LPC1768 microcontroller and an RTOS.
The system controls traffic lights with LED signals, countdown timing, and buzzer alerts during signal transitions.
The project showcases real-time multitasking, accurate timing, and safe state transitions using RTOS scheduling.

#Key Features

🔹 LED-based Traffic Signal Control

Red, Yellow, and Green signal handling.

Predefined time intervals for each signal.

Smooth and reliable state transitions.

🔹 RTOS-based Task Management

Separate RTOS tasks for

Traffic Signal Control

Countdown Timer Update

Buzzer Alerts

Tasks run concurrently, showcasing real-time scheduling.

🔹 Countdown Display

Real-time countdown for each light duration.

Can be shown on LCD / 7-segment display / Serial Monitor.

🔹 Buzzer Alert System

Audible alerts during Yellow-to-Green or Green-to-Red transitions.

Enhances safety by warning pedestrians and vehicles.

🔹 Real-Time Multitasking Demonstration

Uses RTOS features like

Task Delay

Task Priorities

Software Timers

Queues (if used)

Ensures deterministic behaviour and timing accuracy.
