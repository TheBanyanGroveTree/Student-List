/* Description:
   Author: Aahana Sapra
   Date: 10/13/25
 */

#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>

using namespace std;

struct Student {
  char firstName[81];
  char lastName[81];
  int id;
  float gpa;
};

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

    if ((strcmp(userInput, ADD) != 0) && (strcmp(userInput, PRINT) != 0) &&
	(strcmp(userInput, DELETE) != 0) && (strcmp(userInput, QUIT) != 0)) {
      cout << "Please input ADD, PRINT, DELETE, or QUIT." << endl;
    } else {
      cout << "Thank you for reading instructions :)" << endl;
    }
  }
  
  return 0;
}
