#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};

node* binaryTree(){
    int x;
    cout<<"enter value (-1 for null) :";
    cin>>x;

    if(x==-1){
        return NULL;
    }

    node*tmp=new node(x);
    cout<<"enter left value of "<<x <<" ";
    tmp->left=binaryTree();
    cout<<"enter right value of "<<x<<" ";
    tmp->right=binaryTree();

    return tmp;
}

void preOrder(node *tmp){
    if(tmp==NULL){
        return;
    }
    cout<<tmp->data;
    preOrder(tmp->left);
    preOrder(tmp->right);
}

int main(){
    cout<<"enter root node : ";
    node *root;
    root=binaryTree();
    preOrder(root);
    return 0;
}