#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left,*right;

    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

int main(){
    int x;
    int left,right;
    queue<Node*>q;
    
    cout<<"Enter value of root node ";
    cin>>x;

    Node* Root = new Node(x);
    q.push(Root);

    while(!q.empty()){
        Node* tmp=q.front();
        q.pop();

        cout<<"Enter left value of "<<tmp->data<<" ";
        cin>>left;
        if(left!=-1){
            tmp->left = new Node(left);
            q.push(tmp->left);
        }

        cout<<"Enter right value of "<<tmp->data<<" ";
        cin>>right;
        if(right!=-1){
            tmp->right = new Node(right);
            q.push(tmp->right);
        }
    }
}