//
// Created by Rodolfo J. Galván Martínez on 12/3/20.
// This program takes input of any type and allows the user to create and modify a queue.
//

#include <iostream>
#include "Queue.h"
using namespace std;

void menu();
void dataTypes();

int main(int argc, char** argv){
  char choice;
  char dataType;
  bool isDataTypeValid = false;
  Queue<int> intQueue(5);
  Queue<float> floatQueue(5);
  Queue<string> strQueue(5);

  // Prompt the user for
  dataTypes();
  // save the user type preference
  cin >> dataType;

  // verify that the data type is valid
  do{
    if(dataType == '1'
    || dataType == '2'
    || dataType == '3'){
      isDataTypeValid=true;
      cout << endl;
    }else{
      cout << ">> That was not a valid option. Please try again." << endl;
      dataTypes();
      cin >> dataType;
    }
  }while (!isDataTypeValid);


  do {
    menu();
    cin  >> choice;
    if (choice == '1'){ // test enqueue
      string prompt = "   >> What do you want to enqueue? ";
      switch (dataType) {
        case '1': // if int
          int intToQueue;
          cout << prompt;
          cin >> intToQueue;
          cout << endl;
          intQueue.enqueue(intToQueue);
        case '2': // if float
          float floatToQueue;
          cout << prompt;
          cin >> floatToQueue;
          cout << endl;
          floatQueue.enqueue(floatToQueue);
        case '3': // if string
          string strToQueue;
          cout << prompt;
          cin >> strToQueue;
          cout << endl;
          strQueue.enqueue(strToQueue);
      }
    }
    else if (choice == '2'){ // test dequeue
      string outTxt = " was removed from the queue!\n";
      switch (dataType) {
        case '1': // if int
          int intItem;
          intQueue.dequeue(intItem);
          cout << "   >> " << intItem << outTxt;
        case '2': // if float
          float floatItem;
          floatQueue.dequeue(floatItem);
          cout << "   >> " << floatItem << outTxt;
        case '3': // if string
          string strItem;
          strQueue.dequeue(strItem);
          cout << "   >> " << strItem << outTxt;
      }
    }
    else if (choice == '3'){ // display the items in the queue
      switch (dataType) {
        case '1': // if int
          intQueue.display();
        case '2': // if float
          floatQueue.display();
        case '3': // if string
          strQueue.display();
      }
    }
    else if (choice == '4'){
      cout << endl << "Exiting..." << endl << endl;
    }
    else{
      cout << endl << "Not a valid option" << endl << endl;
    }
  } while (choice != '4');
  return 0;
}

void menu(){
  cout << ">> Please choose one of the following:\n"
       << "   * 1 - Put an item in the queue\n"
       << "   * 2 - Remove an item from the queue\n"
       << "   * 3 - Display the items in the queue\n"
       << "   * 4 - Exit"
       << " > ";
}

void dataTypes(){
  cout << ">> What type of data type do you want your queue to hold?\n"
       << "   * 1 - Integer\n"
       << "   * 2 - Float\n"
       << "   * 3 - String\n"
       << " > ";
}