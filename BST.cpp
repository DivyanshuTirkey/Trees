#include<bits/stdc++.h>
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

void preOrder(node * root){
    if(root != NULL){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(node * root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}

int main(){
    node * BST = NULL;
    BST = insert(50,BST);
    insert(30,BST);
    insert(20,BST);
    insert(40,BST);
    insert(70,BST);
    insert(60,BST);
    insert(80,BST);
    cout<<"Inorder traversal"<<endl;
    inOrder(BST);
    cout<<endl<<"preorder traversal"<<endl;
    preOrder(BST);
    cout<<endl<<"postorder traversal"<<endl;
    postOrder(BST);
    cout<<endl;
}