// Project 1
// Ryan Romero      r.romero.softwaredev@gmail.com
// DESCRIPTION:
//

#include <iostream>
#include <array>

using namespace std;

/* -------------------- FUNCTIONS -----------------------*/

void printMenu(){
  cout << endl;
  cout << "---------- Menu ----------" << endl;
  // COUT MENU options
  cout << "Please enter your choice: ";
}

/*
void sortArray(){
    //CODE: use asm
   __asm{}
}
*/


/*
void reverseArray(){
    //CODE: use asm
}
*/

// ANY OTHER FUNCTIONS WISH TO INCLUDE HERE


/* ----------------------- Main --------------------------*/

int main(){
  int myArray[100];
  short arraySize = 0;
  short userChoice = 0;

  cout << "Opening Program" << endl;
  cout << "Enter amount of integers of desired array (max 99): ";
  cin >> arraySize;

  if (arraySize > 99 || arraySize < 0){
      cout << "ERROR: Invalid array size." << endl;
      //Exit program (or create a loop to ask user to input valid size)
  }

  cout << "Enter data to fill your array (integers):" << endl;
  for(int counter=0; counter < arraySize; counter++){
      cin >> myArray[counter];
  }

  cout << "Inputs saved. Current array: ";
  for (counter = 0; counter < arraySize; counter++){
      cout << myArray[counter] << " ";
  }
  cout << endl;

  cout << "What do you wish to do with array?";

  do{
      printMenu();
      cin >> userChoice;
      switch (userChoice)
      {
          case 1:
              //CODE sortArray()
          case 2:
              //CODE reverseArray()

          // . . . .

          default:
      			cout << "Invalid entry." << endl;
      			break;
      		}
      } while (userChoice != // NUM TO EXIT CODE)

      cout << "Exiting Program." << endl;

  }
return 0;
}
