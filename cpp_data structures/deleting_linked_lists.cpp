/* ALGORITHM
    1. ITERATIVE METHOD
        -> find the previous node of the node to be deleted
        -> change the next of the previous node
        ->free memory of the node to be deleted
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//defining a Node
class Node {
public:
    int data;
    Node *next;
};


/*Given a reference (pointer to pointer) to the head
of a list and an int, inserts a new node on the front of the list*/
void push(Node **head_ref, int new_data) {
    //1. allocate a node
    Node *new_node = new Node();

    //2. put in data
    new_node->data = new_data;

    //3. make next of new node as head
    new_node->next = (*head_ref);

    //4. move the head to point to the new node
    (*head_ref) = new_node;
}

/*Given a reference (pointer to pointer) to the head of a list
and a key, deletes the first occurrence of key in the linked list*/
void deleteNode(Node **head_ref, int key) {
    //store head node
    Node *temp= *head_ref;//temp node is referenced as head using head_ref pointer
    Node *prev = NULL;//previous node

    //if head node itself holds the key to be deleted
    if(temp != NULL && temp->data==key) {
        *head_ref = temp->next;//change head
        delete temp; //free old head
        return;
    }

    /*else search for the key to be deleted, keep track of the
    previous node as we need to change 'prev-next'*/
    else {
        while(temp!=NULL && temp->data!=key) {
            prev=temp;
            temp = temp->next;
        }
    }

    //if key was not present in linked list
    if(temp==NULL){
        return;
    }

    //executed only when the key is found and unlinks the node from linked list
    prev->next = temp->next;
    delete temp; //free memory
}

//function prints list contents starting from the given Node
void printList(Node *node) {
    while(node!=NULL) {
        cout<<node->data<<" ";
        node = node->next;
    }
}

//driver code
int main(){
    //start with the empty list
    Node* head = NULL;

    //add elements in linked list
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

    puts("Created Linked List: ");
    printList(head);

    deleteNode(&head, 1);
    puts("\nLInked list after deletion of 1: ");
    printList(head);
    return 0;
}
