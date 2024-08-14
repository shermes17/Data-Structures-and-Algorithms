#include "doublyLinkedSwap.h"

#include <iostream>
#include <string>
#include <sstream>

void swapWithNext(Node * p)
{
    if (p == nullptr)
        return;
    if (p->prev == nullptr)
    {
        Node *swap = p->next; // num after p
        Node *after = p->next->next; // 2 num after p
        p->next = after;
        after->prev = p;
        swap->next = p;
        swap->prev = nullptr;
        return;
        
    }
    if(p->next == nullptr)
        return;
    if(p->next->next == nullptr)
        return;
    Node *before = p->prev; // num before p
    Node *swap = p->next; // num after p
    Node *after = p->next->next; // 2 num after p
    after->prev = p;
    swap->next = p;
    swap->prev = before;
    p->next = after;
    p->prev = swap;
    before->next = swap;
    
}



Node * arrayToList(int array[], int size)
{
    Node * head;
    Node * p;
    int pos = 0;
    if (size > 0)
    {
        head = new Node();
        head->prev = nullptr;
        head->value = 0;
        p = head;
        while (pos < size)
        {
            p->next = new Node();
            p->next->prev = p;
            p = p->next;
            p->value = array[pos];
            pos++;
        }
        p->next = new Node();
        p->next->prev = p;
        p = p->next;
        p->value = 0;
        p->next = nullptr;
    }
    else
    {
        return nullptr;
    }
    return head;
}

//Return pointer to end of the list
Node * getTail(Node * head)
{
    Node * p = head;
    while (p->next != nullptr)
    {
        p = p->next;
    }
    return p;
}

//Return pointer to node with "index"
//First node "index" 0, second node "index" 1, ...
Node * getNode(Node * head, int index)
{
    int pos = 0;
    Node * p = head->next;
    if (pos == index)
    {
        return p;
    }
    else if (index < 0)
    {
        return head;
    }
    else
    {
        while (pos < index && p->next != nullptr)
        {
            p = p->next;
            pos++;
        }
    }
    return p;
}

//Print list forwards from start
void printForwards(Node * head)
{
    Node * p = head->next;
    while (p->next != nullptr)
    {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}

//Print list backwards from end
void printBackwards(Node * tail)
{
    
    Node * p = tail->prev;
    while (p->prev != nullptr)
    {
        
        cout << p->value << " ";
        p = p->prev;
        
        
    }
    cout << endl;
}
//
//int main()
//{
//  int a[] = {2, 3, 5, 7, 11, 13, 17, 19};
//
//  Node * list = arrayToList(a, 8);
//  Node * p = getNode(list, 7);
//
//  int* preswap1_addr = &(p->value);
//  int preswap1_val = p->value;
//
//  swapWithNext(p);
//
//
//  // This can be an ofstream as well or any other ostream
//  stringstream buffer;
//
//  // Save cout's buffer here
//  streambuf *sbuf = cout.rdbuf();
//
//  // Redirect cout to our stringstream buffer or any other ostream
//  cout.rdbuf(buffer.rdbuf());
//
//  printForwards(list);
//  printBackwards(getTail(list));
//
//  int fwd[8];
//  int rev[8];
//  int a_swapped[] = {2, 3, 5, 7, 11, 13, 17, 19};
//  int a_swappedRev[] = {19, 17, 13, 11, 7, 5, 3, 2};
//
//  for (int i=0; i<8; i++)
//  {
//    buffer >> fwd[i];
//  }
//
//  for (int i=0; i<8; i++)
//  {
//    buffer >> rev[i];
//  }
//
//  p = getNode(list, 7);
//
//  int* postswap1_addr = &(p->value);
//  int postswap1_val = p->value;
//
//  // When done redirect cout to its old self
//  cout.rdbuf(sbuf);
//
//  //ASSERT_THAT(fwd, ElementsAreArray(a_swapped));
//  for (int i=0; i<8; i++)
//  {
//    if (fwd[i] != a_swapped[i])
//    {
//      cout << "Mismatch at position " << i << ": expected/correct value " << a_swapped[i] << ", actual value when testing " << fwd[i] << ".\n";
//      return 1;
//    }
//  }
//  //ASSERT_THAT(rev, ElementsAreArray(a_swappedRev));
//  for (int i=0; i<8; i++)
//  {
//    if (rev[i] != a_swappedRev[i])
//    {
//      cout << "Mismatch at position " << i << ": expected/correct value " << a_swappedRev[i] << ", actual value when testing " << rev[i] << ".\n";
//      return 1;
//    }
//  }
//
//  //ASSERT_EQ(preswap1_addr, postswap1_addr);
//  if (preswap1_addr != postswap1_addr)
//  {
//    cout << "preswap1_addr: " << preswap1_addr << " and postswap1_addr " << postswap1_addr << " should be equal.\n";
//    return 1;
//  }
//  //ASSERT_EQ(preswap1_val, postswap1_val);
//  if (preswap1_val != postswap1_val)
//  {
//    cout << "preswap1_val: " << preswap1_val << " and postswap1_val " << postswap1_val << " should be equal.\n";
//    return 1;
//  }
//
//  return 0;
//}
