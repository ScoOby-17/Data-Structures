#include <iostream>
#include<vector>
using namespace std;

void printSubsets(int arr[] , vector<int> &ans, int i){
    if(i==3){
        for(auto val : ans){
            cout<<val <<" ";
        }
        cout<<endl;
        return;
    }

    //include
    ans.push_back(arr[i]);
    printSubsets(arr,ans,i+1);
    ans.pop_back();
    printSubsets(arr,ans,i+1);
}

int main(){
    int arr[] = {1,2,3};
    vector<int>ans;
    printSubsets(arr,ans,0);
}