/***************************************************************
* Name: Benjamin Gaskill
* Course: Principles of Data Structures
* Class: CS04225 Section: 3
* Assignment Date: 03/08/22
* File Name: Gaskill_Assignment1.cpp
*****************************************************************
* 
* ID: Program Assignment #1
* Purpose: Implementing a linked-list queue, representing a
*          vaccination program for Rowan University.
*
*****************************************************************/
#include <iostream>
#include <string>
using namespace std;

// Creating the nodes
struct QNode
{
  string data;
  QNode *next;
    QNode (string d)
  {
    data = d;
    next = NULL;
  }
};

// Creating the queue
struct Queue
{
  QNode *front, *rear;
    Queue ()
  {
    front = rear = NULL;
  }

  // Function to add a value to the queue
  void enQueue (string x)
  {

    // Creating a new Linked-List Node
    QNode *temp = new QNode (x);

    // If the queue is empty, then the 
    // new node is front and rear both 
    if (rear == NULL)
      {
	front = rear = temp;
	return;
      }

    // Adding the new node at the end of the queue
    rear->next = temp;
    rear = temp;
  }
    
  // Function to print the contents of the queue
  void printQueue ()
  {
    QNode *temp = new QNode ("");
    temp = front;
    while (temp != NULL)
      {
	cout << temp->data << " \n";
	temp = temp->next;
      }
  }

  // Function to remove 
  // a key from given queue q 
  void deQueue ()
  {
    // If queue is empty, return NULL. 
    if (front == NULL)
      return;

    // Store previous front and 
    // move front one node ahead 
    QNode *temp = front;
    front = front->next;

    // If front becomes NULL, then 
    // change rear also as NULL 
    if (front == NULL)
      rear = NULL;

    delete (temp);
  }
};

// Main method
int main ()
{
  cout <<
    "***********************************************************************************************\n";
  cout <<
    "             Welcome to the Rowan University vaccination registration program:                 \n";
  cout <<
    "***********************************************************************************************\n\n";
  Queue q;                    // Linked-List Queue Object    
  std::string student = "";  // The name of the student.Used in place of cin to include full names
  string choice;            // Y / N Placeholder
  int counter = 0;         // Current queue position
 
 // Program will continue to collect 10 names
 // and clean the queue for the next 10 names
 // until the user is done (chooses "N")
  while (choice != "N")
  {
    while (counter < 10)
    {
      cout << "Enter the name of the student: ";
      std::getline(cin,student);
      q.enQueue (student);
      counter++;
    }

  cout << "\nQueue in order of FIFO: \n";
  q.printQueue ();

  cout << "\nWould you like to clean the queue (Y/N)"; //add endl
  cin >> choice;
  
  // Cleans the queue
  if (choice == "Y")
    {
      cout << "************************************************\n";
      cout << "              D E - Q U E U I N G               \n";
      cout << "************************************************\n";
      
      for(int i = 0; i <10; i++)
      {
          cout << "Queue Front : " << (q.front)->data << endl;
          cout << "Queue Rear : " << (q.rear)->data << endl;
        q.deQueue ();
      }
      cout << "\nThe queue has been cleaned" << endl;
      counter = -1; //Acts as an offset to ensure 10 students in the list upon additional iterations.
    }
  }
  
  cout << "\nThank you for using the Rowan University vaccination registration program!";
  exit;
}
