#include<iostream>
#include<vector>
using namespace std;

class stack{
    public :
    vector<int>array;

    stack(){
        cout<<"stack is created";
    }

    void push(int val){
            array.push_back(val);
    }

    void pop(){
        if(array.empty()){
            cout<<"empty stack";
            return;
        }
        array.pop_back();
    }

    bool isEmpty(){
        if(array.empty()){
            return true;
        }
        return false;
    }

    int top(){
        if(array.empty()){
            cout<<"empty stack";
            return -1;
        }
        return array.back();
    }

    int size(){
        return array.size();
    }
};

int main(){
    
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<<st.top()<<endl;

    st.pop();
    cout<<st.top()<<endl;

    cout<<st.isEmpty()<<endl;
    cout<<"length of stack is "<< st.size();

    return 0;
}
