### 解题思路
把它看作一个二叉树，左子树当前位置为空，右子树当前位置取值，深度优先遍历进行递归。

### 代码

```cpp
class Solution {
    void dfs(vector<vector<int>>&result,vector<int>&model,int len, int loc, vector<int>& nums);
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> result;
        vector<int> model;
        dfs(result,model,len,0,nums);
        return result;
    }
};

void Solution::dfs(vector<vector<int>>& result, vector<int>& model, int len, int loc, vector<int>& nums)
{
    loc++;
    if (loc < len)dfs(result, model, len, loc,nums);
    else result.push_back(model);
    loc--;
    model.push_back(nums[loc]);
    loc++;
    if (loc < len)dfs(result, model, len, loc, nums);
    else result.push_back(model);
    model.pop_back();
}

```