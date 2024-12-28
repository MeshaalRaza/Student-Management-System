# Student-Management-System
Overview

The Student Management System is a C++ application designed to manage students, instructors, courses, and grades. The system includes functionalities such as enrolling students in courses, assigning instructors to courses, viewing grades, and generating transcripts. It utilizes object-oriented programming principles to provide a robust and modular design.

Features

Student Management:

Enroll students in courses

Drop courses for students

View enrolled courses

Assign grades to students

Generate student transcripts

Instructor Management:

Assign instructors to courses

View courses taught by instructors

Assign grades to students

Course Management:

Add and remove students from courses

Add and view instructors assigned to courses

Display enrolled students

Classes:

Student

Represents a student with attributes like ID, name, date of birth, and contact information. Includes methods for enrolling in courses, dropping courses, viewing enrolled courses, and managing grades.

Instructor

Represents an instructor with attributes like ID, name, and contact information. Includes methods for assigning instructors to courses, displaying taught courses, and managing grades for students.

Course

Represents a course with attributes like course code, title, and capacity. Includes methods for adding/removing students and instructors, and displaying enrolled students and assigned instructors.

Grade

Represents a grade associated with a course. Includes methods to get grade details.

Transcript

Represents a student's transcript containing enrolled courses and grades. Includes methods for adding courses and grades, and printing the transcript.

Menu Options:

The program provides an interactive menu for users to perform the following actions:

Enroll student in a course

Assign instructor to a course

Display enrolled students and instructors for a course

Drop a course for a student

View enrolled courses for a student

Display courses taught by an instructor

Generate transcript for a student

Exit the program
Requirements:

C++ Compiler supporting C++11 or later
License

This project is licensed under the MIT License. See the LICENSE file for details.
