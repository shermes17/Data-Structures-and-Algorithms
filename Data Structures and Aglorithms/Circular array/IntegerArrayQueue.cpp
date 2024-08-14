#include "IntegerArrayQueue.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool IntegerArrayQueue::enqueue(int value)
{
    if((back+1)%size != front)
    {
        array[(back+1)%size] = value;
        back = (back+1)%size;
        return true;
    }
    if((back+1)%size == front && first == true)  // is empty
    {
        first = false;
        array[(back+1)%size] = value;
        back = (back+1)%size;
        return true;
    }
    
    return false;
    
}

int IntegerArrayQueue::dequeue(){

if(back == front )
{
    cout << "Queue is Empty!" << endl;
    return 0;
}
else
{
    int value = array[front];
    array[front] = 0;
    front++;
    return value;
}
    
    return 0;
}
int main()
{
    bool b;

    IntegerArrayQueue queue;

    queue.enqueue(2);
    queue.enqueue(4);
    queue.enqueue(8);
    queue.enqueue(16);
    queue.enqueue(32);
    queue.enqueue(64);
    queue.enqueue(128);
    queue.enqueue(256);
    queue.enqueue(512);
    
    b = queue.enqueue(1024);
    

    queue.printArrayQueue();
    //ASSERT_EQ(b, false);
    if (b != false)
    {
        cout << "expected/correct value false, actual value when testing " << b << ".\n";
        return 1;
    }

    return 0;
}
