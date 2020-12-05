#include <memory>
using namespace std;

template<class T>
class Queue
{
private:
   unique_ptr<T []> queueArray;
   int queueSize;
   int front;
   int rear;
   int numItems;
public:
   Queue(int s);
   void enqueue(T);
   void dequeue(T &);
   bool isEmpty() const;
   bool isFull() const;
   void display() const;
   void clear();
};

