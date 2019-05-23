// Project 1
// Ryan Romero      r.romero.softwaredev@gmail.com
// DESCRIPTION:
//
//          NOTE TO SELF: WORK ON ASM / ARRAY FUNCTIONS NEXT TIME

#include <iostream>
#include <array>

using namespace std;

/*------------------------------- FUNCTIONS ----------------------------------*/

int validInput(int counter){
  int userInput = 0;
  bool isValid = false;
  do
  {
      cout << "Enter data to store in array[" << counter << "]: " << endl;
      cin >> userInput;
      if (cin.good())
      {
          isValid = true;
      }
      else
      {
          userInput = 0;
          cout << "ERROR: not a valid integer" << endl;
      }
  } while(isValid = true);          //Loops while user input isnt an INT
  return userInput;
}

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


/*** ----------------------- Main --------------------------***/

int main()
{
  int myArray[100];
  short arraySize = 0;
  short userChoice = 0;

  cout << "Opening Program" << endl;

/****** ASK USER TO ENTER SIZE OF ARRAY, LOOPS TILL VALID SIZE IS ENTER *******/
  bool validSize = true;
  do
  {
      cout << "Enter amount of integers of desired array (max 99): ";
      cin >> arraySize;
      if ( (arraySize > 99) || (arraySize < 0) )
      {
          cout << "ERROR: Invalid array size." << endl;
          validSize = false;
      }
  }while (validSize == false);
  delete validSize;

/**************** ASK USER TO INPUT INTS INTO ARRAY ***************************/

  for(int counter=0; counter < arraySize; counter++){
      myArray[counter] = validInput(counter);
  }

  cout << endl;
  cout << "Inputs saved. Current array: ";
  for (counter = 0; counter < arraySize; counter++){
      cout << myArray[counter] << " ";
  }
  cout << endl;

  /********** PRINT OUT MENU TILL USER DECIDES TO CLOSE PROGRAM ***************/

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
