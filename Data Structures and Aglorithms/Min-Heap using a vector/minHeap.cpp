
#include "minHeap.h"

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;


void minHeap::siftUp(int pos){
    int parent =floor(pos-1)/2; // parent index
    if(heap[parent] <= heap[pos]) // checks heap property
        return;
    swap(parent,pos); // swaps with parent
    return siftUp(parent);
}

void minHeap::siftDown(int pos){
int leftChild = (2*pos)+1; // left child index
int rightChild = (2*pos)+2; // right child index
int temp = -1; // temporary index variable set out of bounds

if(leftChild < heap.size() && heap[leftChild] < heap[pos]) //Checks left child violates heap property
    temp = leftChild;

if(rightChild < heap.size() && heap[rightChild] < heap[pos]){ //Checks right child violates heap property
    if(temp >= 0){ // checks if left and right both violate the heap property
        if(heap[leftChild] > heap[rightChild]) // gets min
            temp = rightChild;
    }
    else
        temp = rightChild;
    }
    
if(temp >= 0){ // swaps with temp index if temp is in the heap
    swap(temp,pos); //swaps with correct child
    siftDown(temp); // recursion
}
}



minHeap::minHeap(vector<int> data){
    for(int i = 0; i < data.size();i++)
        insert(data[i]);
} 
void minHeap::insert(int value){
    heap.push_back(value); // insert at end
    siftUp(int(heap.size()-1)); // shift up to correct position
}
int minHeap::removeMin(){
    int min = heap[0];
    swap(0,(int)(heap.size()-1)); // swaps with the last value added
    heap.pop_back();
    siftDown(0); // shiftsDown to correct position
    return min;
}

//swap two indicies in the heap
void minHeap::swap(int a, int b){
    int temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
}


void printHeap(minHeap h){
    vector<int> print = h.getHeap();
    for(int i = 0; i < print.size();i++)
        cout << print[i]<< " ";
    cout << endl;
}



//int main(){
//    vector<int> test={1,2,3,4,5,6,7,8,9,10};
//      vector<int> heapTest;
//      minHeap h;
//    
//      h.insert(1);
//      h.insert(2);
//      h.insert(3);
//      h.insert(4);
//      h.insert(5);
//      h.insert(6);
//      h.insert(7);
//      h.insert(8);
//      h.insert(9);
//      h.insert(10);
//    
//      for (int i=0; i<10; i++)
//      {
//        heapTest.push_back(h.removeMin());
//      }
//    printHeap(heapTest);
//    cout << endl;
//    return 0;
//}
