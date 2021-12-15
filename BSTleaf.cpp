#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * newnode(int key){
    node * n = new node;
    n->data = key;
    n->left = n->right = NULL;
    return n;
}

node * insert(int key,node * root){
    if(root == NULL)
       { return newnode(key);}
    if(key<root->data)
        {root->left = insert(key,root->left);}
    else if(key>root->data)
        {root->right = insert(key , root->right);}
    return root;
}

void inOrder(node * root){
    if (root != NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

void printleaf(node * root){
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL){
        cout<<root->data<<" ";
        return;
    }
    if (root->left != NULL)
        printleaf(root->left);
    if (root->right != NULL)
        printleaf(root->right);
}

int main(){
<<<<<<< HEAD
    node * BST = NULL;
    BST = insert(10,BST);
=======
    cout<<"hello";
>>>>>>> temp
}