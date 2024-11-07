
#include <iostream>
#include <queue>
using namespace std;

// lets create the node structure

class node
{
public:
    int data;
    node *left;
    node *right;

    // lets cretae a constructor which puts the value into it at initilixation

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// cretae a function that cretes nodes i.e childs for thr root node

node* Nodebuilder(node* root) {
    cout << "Enter the data for the node" << endl;
    int data;
    cin >> data;

    // If the input is 00, return NULL to represent no node (or stop building further in this branch)
    if (data == 00) {
        return NULL;
    }

    // Create a new node with the given data
    root = new node(data);
    cout << "Currently at node with data: " << root->data << endl;

    // Recursively build the left subtree
    cout << "Enter the data for the node's left part" << endl;
    root->left = Nodebuilder(root->left);
  

    // Recursively build the right subtree
    cout << "Enter the data for the node's right part" << endl;
    root->right = Nodebuilder(root->right);
      

    // Return the constructed root node
    return root;
}
//this is for traversal 


void leverltraversal(node* root) {
    // If the root node is null, simply return
    if (root == NULL) {
        cout << "There is no data in root" << endl;
        return;
    }

    // Make a queue that is going to store the pointers
    queue<node*> q;

    // If the root isn't null, that means there could be some data
    q.push(root);
    q.push(NULL); // Use NULL as a marker for the end of the current level

    // The main thing is here if we print the root data, that means
    // there is a possibility of data in its children
    while (!q.empty()) {
        // Here, current node is pointing to the queue's front
        node* current = q.front();
        q.pop(); // Pop the front of the queue

        // If current is NULL, it indicates the end of a level
        if (current == NULL) {
            cout << endl; // Print a new line for the next level
            if (!q.empty()) {
                q.push(NULL); // Push NULL to mark the end of the next level
            }
        } else {
            // Print the current node's data
            cout << current->data << "  ";

            // Push the left and right children to the queue if they exist
            if (current->left != NULL) {
                q.push(current->left);
            }
            if (current->right != NULL) {
                q.push(current->right);
            }
        }
    }
}
void inorder(node* root) {
    if (root == NULL) {
        return;  // Base case: If the current node is null, return (do nothing)
    }

    inorder(root->left);  // Recursively traverse the left subtree
    cout << root->data << endl;  // Print the data of the current node
    inorder(root->right);  // Recursively traverse the right subtree

}
void preorder(node * root){
    if(root == NULL){
        return;
    }
    cout<<root->data << "  "  ;
    preorder(root->left);
    preorder(root->right);

}
void postorder(node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << "  "; // Print the current node's data
}

int main()
{
    node *root = NULL;

    root = Nodebuilder(root);
     cout << "Post-order traversal of the tree:" << endl;
    postorder(root);
    cout << endl;
}

// 1 3 7 00 00 11 00 00 5 17 00 00 00 