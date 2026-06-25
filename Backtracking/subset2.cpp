#include <iostream>
#include <vector>
#include<set>
using namespace std;

set<vector<int>> s;
void genSubset(vector<int> &nums, vector<int> &subset, int idx)
{
    if (idx == nums.size())
    {
        s.insert(subset);
        return;
    }
    // Generate all subsets

    // include curr val
    subset.push_back(nums[idx]);
    genSubset(nums, subset, idx + 1);
    // exclude curr val
    subset.pop_back();
    genSubset(nums, subset, idx + 1);
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<int> subset;
    genSubset(nums, subset, 0);
    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 2};
    vector<vector<int>> ans = subsetsWithDup(arr);

    for (vector<int> row : ans)
    {
        for (int i = 0; i < row.size(); i++)
        {
            cout << row[i] << " ";
        }
        cout << endl;
    }
}