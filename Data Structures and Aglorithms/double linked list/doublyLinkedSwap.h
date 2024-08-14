#pragma once

#include <iostream>

using namespace std;

//This struct represents a node in a doubly linked list
//containing a "dummy" head and tail node
//Do not modify anything in this file

struct Node{

    int value; //value stored by this node
    Node * prev; //pointer to the previous node in list
    Node * next; //pointer to the next node in list

};

void printBackwards(Node * tail);
void printForwards(Node * head);
Node * getNode(Node * head, int index);
Node * getTail(Node * head);
Node * arrayToList(int array[], int size);
void swapWithNext(Node * p);
