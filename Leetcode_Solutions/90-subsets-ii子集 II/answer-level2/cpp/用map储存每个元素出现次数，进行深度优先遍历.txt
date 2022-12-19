### 解题思路

### 代码

```cpp
class Solution {
    void dfs(map<int,int>::iterator iter,map<int,int> &mmp,vector<int> &model,
         vector<vector<int>> &result,int cho);
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<int, int> mmp;
        vector<vector<int>>result;
        vector<int> model;
        for (int iter : nums) mmp[iter]++;
        auto iter = mmp.begin();
        if (iter != mmp.end()) dfs(iter, mmp,model, result,0);
        return result;
    }
};

void Solution::dfs(map<int, int>::iterator iter, map<int, int>& mmp,
    vector<int> &model, vector<vector<int>>& result,int cho)
{
    for (int i = 0; i < cho;i++)model.push_back(iter->first);
    iter++;
    if (iter != mmp.end()) dfs(iter, mmp, model, result, 0);
    else result.push_back(model);
    iter--;
    for (int i = 0; i < cho; i++)model.pop_back();
    if (cho < iter->second) dfs(iter, mmp, model, result, cho + 1);
}

```