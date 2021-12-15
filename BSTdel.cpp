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

node * delNode(node * root,int key){
    if(root == NULL)
        return root;
    if(root->data > key){
        root->left = delNode(root->left,key);
        return root;
    }

    else if (root->data < key){
        root->right = delNode(root->right,key);
        return root;
    }

    if (root->left == NULL){
        node * temp = root->right;
        delete root;
        return temp;
    }

    else if(root->right == NULL){
        node * temp = root->left;
        delete root;
        return temp;
    }
    
    else{
        //  finding inorder successor
        node * successorP = root;
        node * successor = root->right;
        while(successor->left != NULL){
            successorP = successor;
            successor = successor->left;
        }

        if(successorP != root)
            successorP->left = successor->right;
        else
            successorP->right = successor->right;

        root->data = successor->data;

        delete successor;
        return root;
        
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

    cout<<"inorder traversal"<<endl;
    inOrder(BST);
    cout<<endl;
    cout<<"inorder traversal after deleting a leaf node "<<endl;
    delNode(BST,20);
    inOrder(BST);
    cout<<endl;
    cout<<"inorder traversal after deleting 30 "<<endl;
    delNode(BST,30);
    inOrder(BST);
    cout<<endl;
    cout<<"inorder traversal after deleting 70 "<<endl;
    delNode(BST,70);
    inOrder(BST);
    cout<<endl;


}