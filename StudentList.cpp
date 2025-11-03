/* Description: This program consists of three main functions: add, print, delete.
   The add function prompts the user to input information about a new student, which
   is then stored in a vector of Student struct ptrs. The print function outputs the
   information for all current students. The delete function asks the user for a
   student ID before removing that struct from the vector. Lastly, the program ends 
   with a "QUIT" command.
   Author: Aahana Sapra
   Date: 11/2/25
 */

// library headers
#include <iostream>
#include <vector>
#include <cstring>
#include <limits>
#include <ios>
#include <iomanip>
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
    // read in user input
    cout << "Enter a command (ADD, PRINT, DELETE, QUIT): ";
    cin.getline(userCommand, INPUT_LENGTH);

    // convert input to uppercase for comparison
    for (int i = 0; i < strlen(userCommand); i++) {
      userCommand[i] = toupper(userCommand[i]);
    }
    
    // validate input
    if ((strcmp(userCommand, ADD) != 0) && (strcmp(userCommand, PRINT) != 0) &&
	(strcmp(userCommand, DELETE) != 0) && (strcmp(userCommand, QUIT) != 0)) {
      cout << "Please input ADD, PRINT, DELETE, or QUIT." << endl;
    } else {
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
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear input buffer

  cout << "Enter the student's GPA: ";
  cin >> newStudent->gpa;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  // add student to studentList
  studentList.push_back(newStudent);
}

// define print function that outputs information for all students
void printStudentInfo(vector<Student*> &studentList) {
  for (auto it = studentList.begin(); it != studentList.end(); ++it) {
    // dereference iterator to get to Student* ptr
    cout << (*it)->firstName << ' ' << (*it)->lastName << ", ";
    cout << (*it)->id << ", " << fixed << setprecision(2) << (*it)->gpa << endl; 
  }
}

// delete student from list by using ID to identify them
void deleteStudent(vector<Student*> &studentList) {
  // prompt user for student ID
  int idInput;
  cout << "Enter the student's ID: ";
  cin >> idInput;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  // erase-remove idiom
  // define lambda function to deallocate memory for struct to be removed
  auto studentToRemove = remove_if(studentList.begin(), studentList.end(), [=](Student* ptr) { // capture by val
    if (ptr->id == idInput) {
      delete ptr; // deallocate memory allocated by new operator
      return true; // mark for removal
    }
    return false;
  });

  // erase nullified ptr
  studentList.erase(studentToRemove, studentList.end());
}
