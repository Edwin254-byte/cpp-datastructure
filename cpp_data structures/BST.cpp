#include <iostream>
using namespace std;

struct  Node{
    int data;
    Node *left, *right;
};

class tree{
  int data;
  public:
      tree *left, *right;
      tree(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
      }
      tree* insert(tree *root, int data) {
        if(root ==NULL) {
            root = new tree(data);
            return root;
        }
        if(data <- root->data){
            root->left = insert(root->left,data);
        } else {
            root->right = insert(root->right, data);
            return root;
        }
      }
      void insert(int data) {
        insert(this, data);
      }
      void inorder() {
        if(this->left != NULL)
            this->left->inorder();
        cout << this->data << ", ";
        if(this->right != NULL)
            this->right->inorder();
      }

      void preorder() {
        cout << this->data << ", ";
        if(this->left != NULL)
            this->left->preorder();
        if(this->right != NULL)
            this->right->preorder();
      }

      void postorder() {
        if(this->left != NULL)
            this->left->postorder();
        if(this->right != NULL)
            this->right->postorder();
      cout << this->data << ", ";
      }
};

int main() {
    tree *root = new tree(50);
    for(int i=0; i<10; i++)
        root->insert((rand() % 100));

    cout <<"\ninorder: "; root->inorder();
    cout <<"\npreorder: "; root->preorder();
    cout <<"\npostorder: "; root->postorder();
    cout << endl;

    return 0;
}
