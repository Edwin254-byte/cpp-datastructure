#include <iostream>
using namespace std;

// A linked list node
class Node {
public:
    int data;
    Node* next;
};

//inserts new node at the head
void push(Node **head_ref, int new_data){
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

//given reference to head and a position, deletes the node at the given position
void deleteNode(Node** head_ref, int position) {
    //if linked list is empty
    if(*head_ref == NULL)
        return;

    //store head node
    Node *temp = *head_ref;

    //if head needs to be removed
    if(position == 0) {
        //change head
        *head_ref = temp->next;

        //free old head
        free(temp);
        return;
    }

    //find previous node of the node to be deleted
    for(int i=0; temp !=NULL && i<position - 1; i++)
        temp = temp->next;

    //if the position is more than number of nodes
    if(temp==NULL || temp->next == NULL)
        return;

    //Node temp->next is the node to be deleted
    //store pointer to the next of node to be deleted
    Node *next = temp->next->next;

    //unlink the node from linked list
    free(temp->next);//free memory

    //unlink the deleted node from list
    temp->next=next;
}

//printing node contents
void printList(Node *node) {
    while(node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

//driver code
int main() {
    //start with empty list
    Node *head = NULL;

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);

    cout << "Created Linked List: ";
    printList(head);

    deleteNode(&head, 4);
    cout << "\nLinked List after deletion at position 4: ";
    printList(head);

    return 0;
}
