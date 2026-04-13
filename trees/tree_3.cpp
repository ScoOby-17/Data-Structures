#include <iostream>
#include <queue>
#include <vector>
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

void TraverseByLevel(node* root){
    queue<node*>q;
    node* tmp;
    if(root==NULL){
        cout<<"No value you pass a null pointer";
    }
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            tmp=q.front();
            q.pop();
            cout<<tmp->data<<" ";
            if(tmp->left!=NULL){
                q.push(tmp->left);
            }
            if(tmp->right!=NULL){
                q.push(tmp->right);
            }
        }
        cout<<endl;
    }
}

int sumOfNode(node* root){
    if(root==NULL){
        return 0;
    }
    int ans;
    ans=root->data;
    ans+=sumOfNode(root->left);
    ans+=sumOfNode(root->right);
    return ans;
}

void nonLeaf(node* root,int & count){
    if(root==NULL){
        return ;
    }
    if(root->left!=NULL || root->right!=NULL){
        count++;
        nonLeaf(root->left,count);
        nonLeaf(root->right,count);
    }
}

void leafNode(node* root,int & count){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        count++;
    }
    leafNode(root->left,count);
    leafNode(root->right,count);
}

int main(){
    node*root = binaryTree();
    TraverseByLevel(root);
    cout<<sumOfNode(root)<<endl;
    int count=0;
    nonLeaf(root,count);
    cout<<count;
}