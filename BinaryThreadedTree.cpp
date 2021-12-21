#include<bits/stdc++.h>

using namespace std;

struct node{
    node * left, * right;
    int data;
    bool lthread = false;
    bool rthread = false;
};

node * insert(node * root,int key){
    node * ptr = root;
    node * par = NULL;
    while (ptr != NULL)
    {
        if (key == ptr->data){
            cout<<"Element already exists"<<endl;
            return root;
        }
        par = ptr;
        if(key < ptr->data){
            if(ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        }
        else{
            if(ptr->rthread == false)
                ptr = ptr->right;
            else   
                break;
        }
    }
    // create  new node
    node * tmp = new node;
    tmp->data = key;
    tmp->lthread = tmp->rthread = true;
    // insert new node

    if(par == NULL){
        root = tmp;
        tmp->left = tmp->right = NULL;
    }
    else if(key < par->data){
        tmp->left = par->left;
        tmp->right = par;
        par->lthread = false;
        par->left = tmp;
    }
    else{
        tmp->right = par->right;
        tmp->left = par;
        par->rthread = false;
        par->right = tmp;
    }
    return root;
}

node * inOrderSuccessor(node * ptr){
    if(ptr->rthread == true)
        return ptr->right;

    ptr = ptr->right;
    while(ptr->lthread == false)
        ptr = ptr->left;
    return ptr;
}

void inOrder(node * root){
    node * ptr = root;
    if(root == NULL)
        cout<<"Tree is empty"<<endl;
    while(ptr->lthread == false)
        ptr = ptr->left;
    
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = inOrderSuccessor(ptr);
    }
}

// deletion

void del(node * root,int key){
    node * ptr = root;
    if(root == NULL)
        cout<<"Tree is empty"<<endl;
    while(ptr->lthread == false)
        ptr = ptr->left;
    
    while(ptr != NULL){
        if(ptr->data == key){
            if(ptr->lthread == ptr->rthread == true){
                
            }
        }
        ptr = inOrderSuccessor(ptr);
    }
}

int main(){
    
    struct node *root = NULL;
 
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 16);
    root = insert(root, 14);
    root = insert(root, 17);
    root = insert(root, 13);
 
    inOrder(root);
    cout<<endl;
 
    return 0;

}