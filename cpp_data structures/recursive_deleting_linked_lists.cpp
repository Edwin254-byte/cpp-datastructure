/* ALGORITHM
    2. RECURSIVE METHOD
        ->pass node* (node pointer) as reference to the function (as in node* &head)
        ->now since the current node pointer is derived node's next(which is passed
          by reference) so now if the value of the current node pointer is changed,
          the previous next node's value also gets changed which is required
          operation while deleting a node (i.e points previous node's next to
          current node's (containing key) next).
        ->find the node containing the given value
        ->store this node to deallocate it later using the free function
        ->change this node pointer so that it points to its next and by
           performing the previous node's next also gets properly linked
*/
#include <bits/stdc++.h>
using namespace std;

struct node {
    int info;
    node *link = NULL;
    node() {}
    node(int a)
        :info(a)
    {

    }
};

/*Deletes the node containing 'info' part as val and alter the head
of the linked list (recursive method)*/
void deleteNode(node*& head, int val) {
    /*check if the linked list is empty or we reach at the head of the list*/
    if(head==NULL) {
        cout << "Element not present in the list\n";
        return;
    }
    //if current node is the node to be delete
    if(head->info == val) {
        node* t = head;
        //if it's start at the node head, then node points to 2nd node
        head = head->link;
        //else changes previous node's link to current node's link
        delete(t);
        return;
    }
    deleteNode(head->link, val);
}

/*utility function to add a node in the linked list. Here we are
passing head by reference thud no need to return it to the main function*/
void push(node*&head, int data) {
    node *newNode = new node(data);
    newNode->link = head;
    head = newNode;
}

//utility function printing linked list recursively
void print(node* head) {
    //cout << endl gets implicitly typecasted to bool value 'true'
    if(head==NULL and cout << endl)
        return;
    cout << head->info << ' ';
    print(head->link);
}

//driver code
int main() {
    //starting with empty linked list
    node* head = NULL;

    //add new elements at the beginning of the list
    push(head, 10);
    push(head, 12);
    push(head, 14);
    push(head, 15);

    //original list
    cout << "\ncreated list: ";
    print(head);

    //deletion processes
    deleteNode(head, 20);//call to delete function, 20 is not present
                        // thus no changes in the list
    deleteNode(head,10);
    cout << "\n\nAfter deleting 10: ";
    print(head);

    deleteNode(head, 14);
    cout << "\n\nAfter deleting 14: ";
    print(head);

    return 0;
}


