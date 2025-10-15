/* Description:
   Author: Aahana Sapra
   Date: 10/13/25
 */

#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>

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
  char userInput[INPUT_LENGTH];

  // continue prompting user for input until QUIT command
  bool keepModifying = true;
  while (keepModifying) {
    // read in user input and validate
    cout << "Enter a command (ADD, PRINT, DELETE, QUIT): ";
    cin.getline(userInput, INPUT_LENGTH);
    // invalid input
    if ((strcmp(userInput, ADD) != 0) && (strcmp(userInput, PRINT) != 0) &&
	(strcmp(userInput, DELETE) != 0) && (strcmp(userInput, QUIT) != 0)) {
      cout << "Please input ADD, PRINT, DELETE, or QUIT." << endl;
    }
    // valid input
    else {
      // call appropriate method or exit program
      if (strcmp(userInput, ADD) == 0) {
	addStudent(studentList, INPUT_LENGTH);
      } else if (strcmp(userInput, PRINT) == 0) {

      } else if (strcmp(userInput, DELETE) == 0) {

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
  Student newStudent;
  cout << "Enter the student's first name: ";
  cin.getline(newStudent.firstName, INPUT_LENGTH);
  
  cout << "Enter the student's last name: ";
  cin.getline(newStudent.lastName, INPUT_LENGTH);
  
  cout << "Enter the student's ID: ";
  cin >> newStudent.id;
  cout << endl;

  cout << "Enter the student's GPA: ";
  cin >> newStudent.gpa;
  cout << endl;
}
