/*
    Do an inorder traversal of the treap datastructure.
    Input:
        n - number of nodes
        next n space separated integer contains n number need to be stored
    Output:
        print the inorder traversal in a single line
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key, priority;
    struct Node *left, *right;
};
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    return y;
}

struct Node* newNode(int key)
{
    struct Node* temp = new Node;
    temp->key = key;
    temp->priority = rand()%1000;
    temp->left = temp->right = NULL;
    return temp;
}
struct Node* Search(struct Node* root, int key)
{
    if (root == NULL || root->key == key){
        return root;
    }
    if(root->key < key){
         return Search(root->right, key);
    }
    return Search(root->left, key);
}
struct Node* Insert(struct Node* root, int key)
{
    if(!root){
        return newNode(key);
    }
    if(key <= root->key)
    {
        root->left = Insert(root->left, key);
        if (root->left->priority > root->priority){
             root = rightRotate(root);
        }
    }
    else
    {
        root->right = Insert(root->right, key);
        if (root->right->priority > root->priority){
             root = leftRotate(root);
        }

    }
    return root;
}

struct Node* deleteNode(struct Node* root, int key)
{
    if(root == NULL){
         return root;
    }
    if(key < root->key){
         root->left = deleteNode(root->left, key);
    }
    else if(key > root->key){
        root->right = deleteNode(root->right, key);
    }

    else if(root->left == NULL)
    {
        struct Node *temp = root->right;
        delete(root);
        root = temp;
    }
    else if(root->right == NULL)
    {
        struct Node *temp = root->left;
        delete(root);
        root = temp;
    }

    else if(root->left->priority < root->right->priority)
    {
        root = leftRotate(root);
        root->left = deleteNode(root->left, key);
    }
    else
    {
        root = rightRotate(root);
        root->right = deleteNode(root->right, key);
    }

    return root;
}

void inorder(struct Node* root)
{
    if(root)
    {
        inorder(root->left);
        cout << root->key<<" ";
        inorder(root->right);
    }
}

int main()
{
    srand(time(NULL));

    struct Node *root = NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        root = Insert(root,x);
    }
    inorder(root);
    return 0;
}
