#include <iostream>

class Course;
class Student;
class Instructor;
class Grade;

class Transcript;

class Student
{
private:
    int studentId;
    std::string name;
    std::string dateOfBirth;
    int contactInfo;
    static const int maxEnrolledCourses = 6;
    Course *enrolledCourses[maxEnrolledCourses];
    Grade *grades;
    int numEnrolledCourses;
    int numGrades;

public:
    Student(int = 0, std::string = "", std::string = "01-01-1990", int = 0);
    int getStudentId() const;
    std::string getName() const;

    void enrollInCourse(Course *course);
    void dropCourse(Course *course);
    void viewEnrolledCourses() const;
    void assignGrade(const Grade &grade);
    void viewGrades() const;
    Transcript generateTranscript() const;
};

class Instructor
{
private:
    int instructorId;
    std::string instructorName;
    int contactInfo;
    Course *taughtCourses[5];
    Grade *grades;
    int numGrades;

public:
    Instructor(int = 0, std::string = "", int = 0);

    int getInstructorId() const;
    std::string getInstructorName() const;
    int getContactInfo() const;
    void assignInstructorToCourse(Course *course);
    void displayTaughtCourses() const;
    void assignGradeToStudent(Student *student, Course *course, int grade);
    void viewGradesForStudent(const Student &student) const;
};

class Course
{
private:
    int courseCode;
    std::string title;
    static const int maxCapacity = 50;
    Student **enrolledStudents;
    Instructor **instructors;
    int numEnrolledStudents;
    int numInstructors;

public:
    Course(int = 0, std::string = "None");
    ~Course();

    int getCourseCode() const;
    std::string getTitle() const;

    void addInstructor(Instructor *instructor);
    void displayInstructors() const;
    bool addStudent(Student *student);
    void removeStudent(Student *student);
    void displayEnrolledStudents() const;
};

class Grade
{
private:
    int grade;
    std::string courseTitle;

public:
    Grade(int grade = 0, const std::string &title = "None") : grade(grade), courseTitle(title) {}

    int getGrade() const
    {
        return grade;
    }

    std::string getCourseTitle() const
    {
        return courseTitle;
    }
};

class Transcript
{
private:
    int studentId;
    std::string *enrolledCourses;
    std::string *grades;
    int numEnrolledCourses;
    int numGrades;
    static const int maxCourses = 6;

public:
    Transcript(int id) : studentId(id), enrolledCourses(new std::string[maxCourses]), grades(new std::string[maxCourses]),
                         numEnrolledCourses(0), numGrades(0) {}

    void addCourse(const std::string &course)
    {
        if (numEnrolledCourses < maxCourses)
        {
            enrolledCourses[numEnrolledCourses++] = course;
        }
    }

    void addGrade(const std::string &grade)
    {
        if (numGrades < maxCourses)
        {
            grades[numGrades++] = grade;
        }
    }

    void print() const
    {
        std::cout << "Transcript for Student ID: " << studentId << std::endl;
        std::cout << "Enrolled Courses:" << std::endl;
        for (int i = 0; i < numEnrolledCourses; ++i)
        {
            std::cout << enrolledCourses[i] << std::endl;
        }
        std::cout << "Grades:" << std::endl;
        for (int i = 0; i < numGrades; ++i)
        {
            std::cout << grades[i] << std::endl;
        }
    }

    ~Transcript()
    {
        delete[] enrolledCourses;
        delete[] grades;
    }
};

void displayMenu()
{
    std::cout << "\n===== Menu =====\n";
    std::cout << "1. Enroll student in course\n";
    std::cout << "2. Assign instructor to course\n";
    std::cout << "3. Display enrolled students and instructors for a course\n";
    std::cout << "4. Drop a course for a student\n";
    std::cout << "5. View enrolled courses for a student\n";
    std::cout << "6. Display courses taught by an instructor\n";
    std::cout << "7. Generate Transcript\n";
    std::cout << "0. Exit\n";
}

void enrollStudentInCourse(Student &student, Course &course)
{
    student.enrollInCourse(&course);
}

void assignInstructorToCourse(Instructor &instructor, Course &course)
{
    instructor.assignInstructorToCourse(&course);
}

void displayEnrolledStudentsAndInstructors(const Course &course)
{
    course.displayEnrolledStudents();
    course.displayInstructors();
}

void dropCourseForStudent(Student &student, Course &course)
{
    student.dropCourse(&course);
}

void viewEnrolledCoursesForStudent(const Student &student)
{
    student.viewEnrolledCourses();
}

void displayCoursesTaughtByInstructor(const Instructor &instructor)
{
    instructor.displayTaughtCourses();
}

void generateTranscript(const Student &student)
{
    Transcript transcript(student.getStudentId());
    student.viewEnrolledCourses();
    student.viewGrades();
    // Add more details to the transcript as needed
    transcript.print();
}

int main()
{
    // Create students
    Student student1(1, "abc", "01-01-1995", 123456);
    Student student2(2, "xyz", "02-02-1996", 789012);

    // Create instructors
    Instructor instructor1(101, "qwe", 987654);
    Instructor instructor2(102, "asd", 654321);

    // Create courses
    Course course1(1001, "Introduction to Programming");
    Course course2(1002, "Data Structures");

    int choice;

    do
    {
        displayMenu();

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // Enroll student in course
            int studentId, courseCode;
            std::cout << "Enter student ID: ";
            std::cin >> studentId;
            std::cout << "Enter course code: ";
            std::cin >> courseCode;

            if (studentId == student1.getStudentId() && courseCode == course1.getCourseCode())
            {
                enrollStudentInCourse(student1, course1);
            }

            else if (studentId == student2.getStudentId() && courseCode == course1.getCourseCode())
            {
                enrollStudentInCourse(student2, course1);
            }

            else if (studentId == student2.getStudentId() && courseCode == course2.getCourseCode())
            {
                enrollStudentInCourse(student2, course2);
            }

            else
            {
                std::cout << "Student or course not found.\n";
            }
            break;
        }
        case 2:
        {
            // Assign instructor to course
            int instructorId, courseCode;
            std::cout << "Enter instructor ID: ";
            std::cin >> instructorId;
            std::cout << "Enter course code: ";
            std::cin >> courseCode;

            if (instructorId == instructor1.getInstructorId() && courseCode == course1.getCourseCode())
            {
                assignInstructorToCourse(instructor1, course1);
            }

            else if (instructorId == instructor2.getInstructorId() && courseCode == course2.getCourseCode())
            {
                assignInstructorToCourse(instructor2, course2);
            }

            else
            {
                std::cout << "Instructor or course not found.\n";
            }
            break;
        }

        case 3:
            // Display enrolled students and instructors for a course
            int courseCode;
            std::cout << "Enter course code: ";
            std::cin >> courseCode;

            if (courseCode == course1.getCourseCode())
            {
                displayEnrolledStudentsAndInstructors(course1);
            }

            else if (courseCode == course2.getCourseCode())
            {
                displayEnrolledStudentsAndInstructors(course2);
            }

            else
            {
                std::cout << "Course not found.\n";
            }
            break;

        case 4:
        {
            // Drop a course for a student
            int studentId, courseCode;
            std::cout << "Enter student ID: ";
            std::cin >> studentId;
            std::cout << "Enter course code: ";
            std::cin >> courseCode;

            if (studentId == student1.getStudentId() && courseCode == course1.getCourseCode())
            {
                dropCourseForStudent(student1, course1);
            }

            else
            {
                std::cout << "Student or course not found.\n";
            }
            break;
        }

        case 5:
        {
            // View enrolled courses for a student
            int studentId;
            std::cout << "Enter student ID: ";
            std::cin >> studentId;

            if (studentId == student1.getStudentId())
            {
                viewEnrolledCoursesForStudent(student1);
            }

            else if (studentId == student2.getStudentId())
            {
                viewEnrolledCoursesForStudent(student2);
            }

            else
            {
                std::cout << "Student not found.\n";
            }
            break;
        }

        case 6:
        {
            // Display courses taught by an instructor
            int instructorId;
            std::cout << "Enter instructor ID: ";
            std::cin >> instructorId;

            if (instructorId == instructor1.getInstructorId())
            {
                displayCoursesTaughtByInstructor(instructor1);
            }

            else if (instructorId == instructor2.getInstructorId())
            {
                displayCoursesTaughtByInstructor(instructor2);
            }

            else
            {
                std::cout << "Instructor not found.\n";
            }
            break;
        }

        case 7:
            // Generate Transcript
            int studentId;
            std::cout << "Enter student ID: ";
            std::cin >> studentId;

            if (studentId == student1.getStudentId())
            {
                generateTranscript(student1);
            }

            else if (studentId == student2.getStudentId())
            {
                generateTranscript(student2);
            }

            else
            {
                std::cout << "Student not found.\n";
            }
            break;

        case 0:
            std::cout << "Exiting program.\n";
            break;

        default:
            std::cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 0);

    return 0;
}


Student::Student(int id, std::string studentName, std::string dob, int contact)
    : studentId(id), name(studentName), dateOfBirth(dob), contactInfo(contact),
      numEnrolledCourses(0), grades(NULL), numGrades(0) {}


int Student::getStudentId() const 
{
	return studentId;
}

std::string Student::getName() const 
{
	return name;
}

void Student::enrollInCourse(Course* course) 
{
	if(numEnrolledCourses < maxEnrolledCourses) 
	{
		enrolledCourses[numEnrolledCourses++] = course;
		course->addStudent(this);
		std::cout << "Enrolled in the course: " << course->getTitle() << std::endl;
	} 

	else 
	{
		std::cout << "Cannot enroll in more courses." << std::endl;
	}
}

void Student::dropCourse(Course* course) 
{
	for(int i = 0; i < numEnrolledCourses; ++i) 
	{
		if(enrolledCourses[i] == course) 
		{
			for (int j = i; j < numEnrolledCourses - 1; ++j) 
			{
				enrolledCourses[j] = enrolledCourses[j + 1];
			}
			--numEnrolledCourses;
			std::cout << "Dropped course: " << course->getTitle() << std::endl;
			return;
		}
	}
	std::cout << "Course not found in the enrolled courses." << std::endl;
}

void Student::viewEnrolledCourses() const 
{
	std::cout << "Enrolled Courses for " << name << " (Student ID: " << studentId << "):" << std::endl;
	for(int i = 0; i < numEnrolledCourses; ++i) 
	{
		std::cout << "Course Code: " << enrolledCourses[i]->getCourseCode() << ", Course Title: " << enrolledCourses[i]->getTitle() << std::endl;
	}
}



void Student::assignGrade(const Grade& grade) {
    Grade* newGrades = new Grade[numGrades + 1];
    for (int i = 0; i < numGrades; ++i) {
        newGrades[i] = grades[i];
    }
    newGrades[numGrades++] = grade;
    delete[] grades;
    grades = newGrades;
}

void Student::viewGrades() const {
    std::cout << "Grades for " << name << " (Student ID: " << studentId << "):" << std::endl;
    for (int i = 0; i < numGrades; ++i) {
        std::cout << "Course: " << grades[i].getCourseTitle() << ", Grade: " << grades[i].getGrade() << std::endl;
    }
}


////////////////////////////////////////////////////////////////

Instructor::Instructor(int id, std::string name, int contact)
	: instructorId(id), instructorName(name), contactInfo(contact) 
{
	for(int i = 0; i < 5; ++i) 
	{
		taughtCourses[i] = NULL;
	}
}


int Instructor::getInstructorId() const 
{
	return instructorId;
}

std::string Instructor::getInstructorName() const 
{
	return instructorName;
}

int Instructor::getContactInfo() const 
{
	return contactInfo;
}

void Instructor::assignInstructorToCourse(Course* course) 
{
	for(int i = 0; i < sizeof(taughtCourses)/sizeof(taughtCourses[0]); ++i) 
	{
		if (taughtCourses[i] == NULL) 
		{
			taughtCourses[i] = course;
			std::cout << "Instructor " << instructorName << " assigned to course " << course->getTitle() << std::endl;
			return;
		}
	}
	std::cout << "Cannot assign more courses to instructor " << instructorName << std::endl;
}

void Instructor::displayTaughtCourses() const
{
	std::cout << "Courses taught by " << instructorName << " (Instructor ID: " << instructorId << "):" << std::endl;
	for(int i = 0; i < sizeof(taughtCourses)/sizeof(taughtCourses[0]); ++i) 
	{
		if (taughtCourses[i] != NULL) 
		{
			std::cout << "Course Code: " << taughtCourses[i]->getCourseCode() << ", Course Title: " << taughtCourses[i]->getTitle() << std::endl;
		}
	}
}


void Instructor::assignGradeToStudent(Student* student, Course* course, int gradeValue) {
    Grade newGrade(gradeValue, course->getTitle());
    student->assignGrade(newGrade);
    Grade* newGrades = new Grade[numGrades + 1];
    for (int i = 0; i < numGrades; ++i) {
        newGrades[i] = grades[i];
    }
    newGrades[numGrades++] = newGrade;
    delete[] grades;
    grades = newGrades;
    std::cout << "Assigned grade " << gradeValue << " to student " << student->getName()
              << " in course " << course->getTitle() << std::endl;
}

void Instructor::viewGradesForStudent(const Student& student) const {
    std::cout << "Grades given by " << instructorName << " for " << student.getName() << ":" << std::endl;
    for (int i = 0; i < numGrades; ++i) {
        std::cout << "Course: " << grades[i].getCourseTitle() << ", Grade: " << grades[i].getGrade() << std::endl;
    }
}

/////////////////////////////////////////////////////////////////////

Course::Course(int code, std::string title)
	: courseCode(code), title(title), numInstructors(0), numEnrolledStudents(0)
{
	enrolledStudents = new Student*[maxCapacity];
	instructors = new Instructor*[3];

	for(int i = 0; i < maxCapacity; ++i)
	{
		enrolledStudents[i] = NULL;
	}

	for(int i = 0; i < 3; ++i)
	{
		instructors[i] = NULL;
	}
}

Course::~Course()
{
	delete[] enrolledStudents;
	delete[] instructors;
}

int Course::getCourseCode() const
{
	return courseCode;
}

std::string Course::getTitle() const
{
	return title;
}

bool Course::addStudent(Student* student)
{
	if (numEnrolledStudents < maxCapacity)
	{
		enrolledStudents[numEnrolledStudents++] = student;
		return true;
	}
	else
	{
		std::cout << "Course is at full capacity. Cannot enroll more students." << std::endl;
		return false;
	}
}

void Course::removeStudent(Student* student)
{
	for (int i = 0; i < numEnrolledStudents; ++i)
	{
		if (enrolledStudents[i] == student)
		{
			for (int j = i; j < numEnrolledStudents - 1; ++j)
			{
				enrolledStudents[j] = enrolledStudents[j + 1];
			}

			--numEnrolledStudents;
			std::cout << "Removed student from the course: " << student->getName() << std::endl;
			return;
		}
	}
	std::cout << "Student not found in the course." << std::endl;
}

void Course::displayEnrolledStudents() const
{
	std::cout << "Enrolled Students in " << title << " (Course Code: " << courseCode << "):" << std::endl;
	for (int i = 0; i < numEnrolledStudents; ++i)
	{
		std::cout << "Student ID: " << enrolledStudents[i]->getStudentId() << std::endl;
	}
}

void Course::addInstructor(Instructor* instructor)
{
	if (numInstructors < 3)
	{
		instructors[numInstructors++] = instructor;
		std::cout << "Instructor " << instructor->getInstructorName() << " added to course " << title << std::endl;
	}

	else
	{
		std::cout << "Course already has the maximum number of instructors." << std::endl;
	}
}

void Course::displayInstructors() const
{
	std::cout << "Instructors for " << title << " (Course Code: " << courseCode << "):" << std::endl;
	for (int i = 0; i < numInstructors; ++i)
	{
		std::cout << "Instructor Name: " << instructors[i]->getInstructorName() << std::endl;
	}
}
