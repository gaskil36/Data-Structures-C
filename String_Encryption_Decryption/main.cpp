/***************************************************************
* Name: Benjamin Gaskill
* Course: Principles of Data Structures
* Class: CS04225 Section: 3
* Assignment Date: 03/31/22
* File Name: Gaskill_Assignment2.cpp
*****************************************************************
* ID: Program Assignment #2
* Purpose: Implementing a encryption-decryption program for a 
*          given string.
*****************************************************************/

#include <iostream>
using namespace std; 

// Main Method
int main()
{
   // Formatted text for display
   cout << "**********************************************************************************" << endl; 
   cout << "* This program will encrypt a message stored in an array by using a hash function" << endl;
   cout << "**********************************************************************************" << endl;
  
   // Declaring an array of characters 
   char x[21] = "Resistance is futile";
   
   // Printing the original message
   cout << "\nThe original message is: " << x << endl;
   
   // Loop to iterate through the array of characters
   // Applying the hash algorithm
   for(int i = 0; i < sizeof(x); i++)
   {
       x[i] = int(x[i] + 8);
   }
   
   // Printing the encrypted message
   cout << "The encrypted message is: " << x << endl;

   // Loop to iterate through the array of characters
   // Applying the reverse hash algorithm
   for(int i = 0; i < sizeof(x); i++)
   {
       x[i] = int(x[i] - 8);
   }
   
   // Printing the decrypted message
   cout << "The decrypted message is: " << x << endl;
   return 0;
}