#include <iostream>
#include "Queue.h"
#include <cstdlib>

using namespace std;

//*************************
// Constructor.           *
//*************************
template<class T>
Queue<T>::Queue(int s)
{
   queueArray = make_unique<T []>(s);
   queueSize = s;
   front = -1;
   rear = -1;
   numItems = 0;
}


//********************************************
// Function enqueue inserts the value in item *
// at the rear of the queue.                 *
//********************************************
template<class T>
void Queue<T>::enqueue(T item)
{
   if (isFull())
   {
      cout << "The queue is full.\n";
      exit(1);
   }
   else
   {
      // Calculate the new rear position
      rear = (rear + 1) % queueSize;      
      // Insert new item
      queueArray[rear] = item;
      // Update item count
      numItems++;
   }
}

//**********************************************
// Function dequeue removes the value at the   *
// front of the queue, and copies it into item. *
//**********************************************
template<class T>
void Queue<T>::dequeue(T &item)
{
   if (isEmpty())
   {
      cout << "The queue is empty.\n";
      exit(1);
   }
   else
   {
      // Move front
      front = (front + 1) % queueSize;
      // Retrieve the front item
      item = queueArray[front];
      // Update item count		
      numItems--;
   }
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise.             *
//*********************************************
template<class T>
bool Queue<T>::isEmpty() const
{
   return numItems == 0;
}

//********************************************
// Function isFull returns true if the queue *
// is full, and false otherwise.             *
//********************************************
template<class T>
bool Queue<T>::isFull() const
{
   return numItems == queueSize;
}

//**********************************************
// Function display, displays the entire queue *
// is full, and false otherwise.               *
//**********************************************
template<class T>
void Queue<T>::display() const {
  if (!isEmpty()){
    for (int i = 0; i <= queueSize; i++){
      cout << " * " << queueArray[i] << endl;
    }
  }else{
    cout << "There's nothing in the queue so far. \n";
  }
}

//*******************************************
// Function clear resets the front and rear *
// indices, and sets numItems to 0.         *
//*******************************************
template<class T>
void Queue<T>::clear()
{
   front = -1;
   rear = -1;
   numItems = 0;
}

