// Project 1
// Ryan Romero      r.romero.softwaredev@gmail.com
// DESCRIPTION:
//              This is a program that ask user to input num for an array.
//  program can sort or reverse array. Functions to do so are writen in ASM

#include <iostream>
#include <array>

using namespace std;

//------------------------------------------------------------------------------
/*------------------------------- FUNCTIONS ----------------------------------*/

int validInput(int counter){
  int userInput = 0;
  bool isValid = false;
  do
  {
      cout << "Enter data to store in array[" << counter << "]: " << endl;
      cin >> userInput;
      if (cin.good())               //Check if valid integer
      {
          isValid = true;
      }
      else
      {
          userInput = 0;
          cout << "ERROR: not a valid integer" << endl;
      }
  } while(isValid == true);          //Loops while user input isnt an integer
  return userInput;
}

void printMenu(){
  cout << endl;
  cout << "---------- Menu ----------" << endl;
  cout << "1. Sort Array" << endl;
  cout << "2. Reverse Array" << endl;
  cout << "3. Set new Array" << endl;
  cout << "4. End Proogram" << endl;
  cout << endl;
  cout << "Please enter your choice: ";
}
//------------------------------------------------------
void sortArray(int myArray[]){
   __asm{
      push  eax       //
      push  ebx       // Saves any info in these regs.
      push  ecx       //
      push  esi       // regs will be use during the function
      push  edi       //

      mov   ecx, LENGTHOF myArray                 // counter
      mov   esi, OFFSET myArray                   // ptr to first element in array
      Loop1:
          mov   ebx, [esi]                  // saves element x into EBX
          mov   edi, esi                    // copy ptr to first element to EDI
          mov   eax, ecx                    // copy counter to EAX
          push  ecx                         // Saves counte
          mov   ecx, eax                    // ECX and EAX = counter
      Loop2:
          add   edi, TYPE myArray           // EDI now points to next element [ x + 1 ]
          cmp   ebx, [edi]                  // Compare element [ X ] and [ x+1 ] in myArray
          jge   SkipCode                    // IF [x] > [x+1], skips following lines of code
          mov   ebx, [edi]                  // EBX, now holds what was the next element (moving up array)
          mov   eax, ecx                    // EAX = current counter
          sub   eax, TYPE myArray           // counter--
      SkipCode:
          loop  Loop2
          mov   edi, OFFSET myArray + SIZEOF myArray  //
          sub   edi, eax
          xchg  [esi], ebx
          mov   [edi], ebx
          add   esi, TYPE myArray
          pop   ecx
          loop  Loop1

      pop   edi       // Pops all regs that were use
      pop   esi       //
      pop   ecx       //
      pop   ebx
      pop   eax
   };
}
//--------------------------------------------------------
void reverseArray(int myArray[]){
    __asm{
        push  eax
        push  ebx
        push  ecx
        push  edi
        push  esi

        mov   ecx, LENGTHOF myArray / 2    // loop counter
        mov   esi, OFFSET myArray                                   // Ptr to first element
        mov   edi, OFFSET myArray + SIZEOF myArray - TYPE myArray   // Ptr to last element

        myLoop:
            mov   eax, [esi]    //move element to reg
            mov   ebx, [edi]    //move element to reg
            mov   [esi], ebx    //swap
            mov   [edi], eax    //swap
            add   esi, TYPE myArray   //inc
            sub   edi, TYPE myArray   //dec
            loop myLoop

        pop   esi
        pop   edi
        pop   ecx
        pop   ebx
        pop   eax
    };
}
//----------------------------------------------------
void setArray(int myArray[], short arraySize)
{
  /******* ASK USER TO INPUT SIZE OF ARRAY *********/
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
        else
            {validSize = true;}

    }while (validSize == false);

  /******** ASK USER TO INPUT NUMS INTO ARRAY ************/

    for(short counter=0; counter < arraySize; counter++)
    {
        myArray[counter] = validInput(counter);
    }
    cout << endl;
    cout << "Inputs saved. Current array: ";
    for (int counter = 0; counter < arraySize; counter++)
    {
        cout << myArray[counter] << " ";
    }
    cout << endl;
}



//-------------------------------------------------------------------------
/*** ---------------------------- Main ------------------------------- ***/
int main()
{
  int myArray[100];
  short arraySize = 0;
  short userChoice = 0;

  cout << "Opening Program" << endl;
  setArray(myArray, arraySize);          // sets arrays

  /********** PRINT OUT MENU TILL USER DECIDES TO CLOSE PROGRAM ***************/
  cout << "What do you wish to do with array?";
  do{
      printMenu();                                  // prints menu
      cin >> userChoice;
      switch (userChoice)
      {
            case 1:                                 // sorts array
              sortArray(myArray);
              break;

          case 2:
              reverseArray(myArray);                // reverse array
              break;

          case 3:                                   // resets array, sets array
              for(short i = 0; i <arraySize; i++)
              {
                  myArray[i] = 0;
              }
              arraySize = 0;
              setArray(myArray, arraySize);
              break;

          case 4:                                    // quits program
              // END PROGRAM
              break;

          default:                                   // default case
      			cout << "Invalid entry." << endl;
      			break;
      		}
      } while (userChoice != 4);

      cout << "Exiting Program." << endl;
return 0;
}
