#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//defining a Node
class Node {
public:
    int data;
    Node *next;
};

//prints content of linked list starting
//from any given node
void printList(Node *n) {
    while(n!=NULL) {
        cout<< n->data << " ";
        n = n->next;
    }
}

int main()
{
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    //allocate 3 nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;//assign data to first node
    head->next = second;//link the first node with the second node

    second->data = 2; //assign data to second node
    second->next = third;

    third->data = 3; //assign data to third node
    third -> next = NULL;

    printList(head);//traversing each node from the head

    return 0;
}
