/* Description:
   Author: Aahana Sapra
   Date: 10/22/25
 */

// import relevant libraries
#include <iostream>
#include <vector>
#include <cstring>
#include <limits>
#include <ios>
#include <algorithm>

using namespace std;

// define Student struct
struct Student {
  char firstName[81];
  char lastName[81];
  int id;
  float gpa;
};

// define function prototypes
void addStudent(vector<Student*> &studentList, const int &INPUT_LENGTH);
void printStudentInfo(vector<Student*> &studentList);
void deleteStudent(vector<Student*> &studentList);

int main() {
  // create vector of struct pointers
  vector<Student*> studentList;

  // define const var for commands
  const char ADD[] = "ADD";
  const char PRINT[] = "PRINT";
  const char DELETE[] = "DELETE";
  const char QUIT[] = "QUIT";

  // declare char arr for user input
  const int INPUT_LENGTH = 81;
  char userCommand[INPUT_LENGTH];

  // continue prompting user for input until QUIT command
  bool keepModifying = true;
  while (keepModifying) {
    // read in user input and validate
    cout << "Enter a command (ADD, PRINT, DELETE, QUIT): ";
    cin.getline(userCommand, INPUT_LENGTH);
    // invalid input
    if ((strcmp(userCommand, ADD) != 0) && (strcmp(userCommand, PRINT) != 0) &&
	(strcmp(userCommand, DELETE) != 0) && (strcmp(userCommand, QUIT) != 0)) {
      cout << "Please input ADD, PRINT, DELETE, or QUIT." << endl;
    }
    // valid input
    else {
      // call appropriate method or exit program
      if (strcmp(userCommand, ADD) == 0) {
	addStudent(studentList, INPUT_LENGTH);
      } else if (strcmp(userCommand, PRINT) == 0) {
	printStudentInfo(studentList);
      } else if (strcmp(userCommand, DELETE) == 0) {
	deleteStudent(studentList);
      } else {
	keepModifying = false;
      }
    }
  }
  
  return 0;
}

// define add function to create a new student entry
void addStudent(vector<Student*> &studentList, const int &INPUT_LENGTH) {
  // read in user input and update student information
  // dynamically allocate new struct instance (add to heap)
  Student* newStudent = new Student();
  cout << "Enter the student's first name: ";
  // -> operator dereferences and accesses obj mbr in one step
  cin.getline(newStudent->firstName, INPUT_LENGTH);
  
  cout << "Enter the student's last name: ";
  cin.getline(newStudent->lastName, INPUT_LENGTH);
  
  cout << "Enter the student's ID: ";
  cin >> newStudent->id;
  // QUESTION: how does this work...?
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear input buffer

  cout << "Enter the student's GPA: ";
  cin >> newStudent->gpa;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  // add student to studentList
  studentList.push_back(newStudent);
}

// define print function that outputs information for all students
void printStudentInfo(vector<Student*> &studentList) {
  // QUESTION: why ++it instead of it++?
  // ALTERNATIVE: range-based for loop
  for (auto it = studentList.begin(); it != studentList.end(); ++it) {
    cout.precision(2);
    // dereference iterator to get to Student* ptr
    // QUESTION: is an iterator a ptr.. why "dereference it"
    cout << (*it)->firstName << ' ' << (*it)->lastName << ", ";
    cout << (*it)->id << ", " << (*it)->gpa << endl; 
  }
}

// delete student from list by using ID to identify them
void deleteStudent(vector<Student*> &studentList) {
  // prompt user for student ID
  int idInput;
  cout << "Enter the student's ID: ";
  cin >> idInput;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  // delete student that corresponds to specified ID
  for (auto it = studentList.begin(); it != studentList.end(); ++it) {
    if ((*it)->id == idInput) {
      delete *it; // deallocate memory allocated by new operator
      studentList.erase(remove(studentList.begin(), studentList.end(), *it)); // remove element from vector
    }
  }
}
