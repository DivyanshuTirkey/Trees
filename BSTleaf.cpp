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

unsigned int getLeafCount(struct node* node)
{
    if(node == NULL)    
        return 0;
    if(node->left == NULL && node->right == NULL)
        return 1;        
    else
        return getLeafCount(node->left)+
            getLeafCount(node->right);
}

int main(){
    node * BST = NULL;
    BST = insert(1,BST);
    insert(2,BST);
    insert(4,BST);
    insert(3,BST);
    insert(5,BST);
    insert(6,BST);
    insert(7,BST);
    insert(8,BST);
    insert(9,BST);
    insert(10,BST);
    cout<<"number of leaves "<<getLeafCount(BST);
    cout<<endl;
}