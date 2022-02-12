// Project 1
// Ryan Romero      r.romero.softwaredev@gmail.com
// DESCRIPTION:
//              This is a program that ask user to input num for an array.
//  program can sort or reverse array. Functions to do so are writen in ASM
//  the rest is written in C++

#include <iostream>
#include <array>
using namespace std;


/*-----------------------------------------------------------------------------
/ validInput(): Get 1 number from user and check if it's a valid inputs before
/               saving it into the array. This function is called for every
/               element in the user array in setArray()
/----------------------------------------------------------------------------*/
int validInput(int counter)
{
    int userInput = 0;
    bool isValid = false;
    do
    {
        cout << "Enter data to store in array[" << counter << "]: " << endl;
        cin >> userInput;
        if (cin.good())               //Check if valid integer
        {
            isValid = true;           //TRUE: exit loop and returns
        }
        else                          //FALSE: ask user to enter valid integer
        {
            userInput = 0;
            cout << "ERROR: not a valid integer" << endl;
        }
    } while(isValid == true);          //Loops while user input isnt an integer
    return userInput;
}



/*----------------------------------------------------------------------------
/ setArray(): Ask user for size of their array. It then ask user to input
/             every individual value of the array. Lastly, it displays
/             user's array.
/ --------------------------------------------------------------------------*/
void setArray(int myArray[], short arraySize)
{
    /******* ASK USER TO INPUT SIZE OF ARRAY *********/
    bool validSize = true;
    do
    {
        cout << "Enter amount of integers of desired array (max 99): ";
        cin >> arraySize;
        if( (arraySize > 99) || (arraySize < 0) )          // check if user define size is within intialize array size (of 100)
        {
            cout << "ERROR: Invalid array size." << endl;   // FALSE: ask user to enter valid size
            validSize = false;
        }
        else                                                // TRUE: exit loop and moves on
        {
          validSize = true;
        }

    } while(validSize == false);


    /******** ASK USER TO INPUT NUMBERS INTO ARRAY ************/
    for(short counter=0; counter < arraySize; counter++)
    {
      myArray[counter] = validInput(counter);             // calls function "validInput()" where it gets numbers from user and checks if they r valid inputs
    }


    /******** DISPLAY USER's ARRAY  ************/
    cout << endl;
    cout << "Inputs saved. Current array: ";                // display entire array with the valid inputs user has choose
    for (short counterB = 0; counterB < arraySize; counterB++)
    {
        cout << myArray[counterB] << " ";
    }
    cout << endl;
}



/*----------------------------------------------------------------------------
/ printMenu(): Displays a series of options user can choose from. Can choose
/              to have their array sorted, reversed, or create a new array.
/----------------------------------------------------------------------------*/
void printMenu()
{
    cout << endl;
    cout << "---------- Menu ----------" << endl;
    cout << "1. Sort Array" << endl;
    cout << "2. Reverse Array" << endl;
    cout << "3. Set new Array" << endl;
    cout << "4. End Program" << endl;
    cout << endl;
    cout << "Please enter your choice: ";
}



/*----------------------------------------------------------------------------
/ sortArray(): ASM code that sorts array
/----------------------------------------------------------------------------*/
void sortArray(int myArray[])
{
    __asm
    {
       push  eax       //
       push  ebx       // initialize registers that will be used to sort array
       push  ecx       //
       push  esi       // these regs will be use during the function
       push  edi       //

       mov   ecx, LENGTHOF myArray                 // ECX = counter
       mov   esi, OFFSET myArray                   // ESI = ptr to first element in array
       Loop1:
           mov   ebx, [esi]                  // saves element into EBX
           mov   edi, esi                    // EDI = copy ptr to first element
           mov   eax, ecx                    // EAX = copy counter
           push  ecx                         // Saves counter
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
           mov   edi, OFFSET myArray + SIZEOF myArray
           sub   edi, eax
           xchg  [esi], ebx
           mov   [edi], ebx
           add   esi, TYPE myArray
           pop   ecx
           loop  Loop1

       pop   edi       //
       pop   esi       // Pops all regs that were used
       pop   ecx       //
       pop   ebx       // free up reg to be used by other processes
       pop   eax       //
    }
}



/*----------------------------------------------------------------------------
/ reverseArray: ASM code to reverse array
/----------------------------------------------------------------------------*/
void reverseArray(int myArray[])
{
    __asm
    {
        push  eax     //
        push  ebx     //
        push  ecx     // initialize registers that will be used to reverse array
        push  edi     //
        push  esi     //

        mov   ecx, LENGTHOF myArray / 2                             // loop counter
        mov   esi, OFFSET myArray                                   // Ptr to first element
        mov   edi, OFFSET myArray + SIZEOF myArray - TYPE myArray   // Ptr to last element

        myLoop:
            mov   eax, [esi]          //move element to reg EAX
            mov   ebx, [edi]          //move element to reg EBX
            mov   [esi], ebx          //swap elements
            mov   [edi], eax          //swap elements
            add   esi, TYPE myArray   //increment ptr (that started at first element)
            sub   edi, TYPE myArray   //decrement ptr (that started at last element)
            loop myLoop

        pop   esi     //
        pop   edi     // Pops all regs that were used
        pop   ecx     //
        pop   ebx     // frees up reg to be used by processes
        pop   eax     //
    }
}



/*----------------------------------------------------------------------------
/ ---------------------------- MAIN FUNCTION ---------------------------------
/----------------------------------------------------------------------------*/
int main()
{
    /**** INITIALIZE VARIABLES ****/
    int myArray[100];
    short arraySize = 0;
    short userChoice = 0;


    /**** START PROGRAM (set the very first array) ****/
    cout << "Opening Program" << endl;
    setArray(myArray, arraySize);


    /**** PRINT OUT MENU ****/
    cout << "What do you wish to do with array?";
    do
    {
        printMenu();                                // prints menu
        cin >> userChoice;                          // get user choice
        switch (userChoice)
        {
            case 1:                                 // if choice = 1
                sortArray(myArray);                 // sorts array
                break;

            case 2:                                 // if choice = 2
                reverseArray(myArray);              // reverse array
                break;

            case 3:                                   // if choice = 3
                for(short i = 0; i <arraySize; i++)   // resets array
                {
                    myArray[i] = 0;
                }
                arraySize = 0;
                setArray(myArray, arraySize);       // sets new values for array
                break;

            case 4:                                 // if choice = 4
                // END PROGRAM                      // exits the switch cases, (goes to end of main)
                break;

            default:                                // default case
      			    cout << "Invalid entry." << endl;
      			    break;
      	}
    } while (userChoice != 4);
    cout << "Exiting Program." << endl;

    return 0;
}
