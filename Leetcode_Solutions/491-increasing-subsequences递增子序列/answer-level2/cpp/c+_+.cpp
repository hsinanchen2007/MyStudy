### 解题思路
好好读题，，，第一次做的时候还对原数组排了个序，人家都说是子序列叻。。。。。。。。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0);
        sort(ans.begin(), ans.end());
        vector<int> t = vector<int>({});
        for(int i = 0;i < ans.size();++i){
            if(ans[i] == t) continue;
            res.push_back(ans[i]);
            t = ans[i];
        }
        return res;
    }
    void dfs(vector<int>& nums,int u){
        if(path.size() > 1)
            ans.push_back(path);
        if(u == nums.size())return;
        for(int i = u;i < nums.size();++i){
            if(path.size() && nums[i] < path.back())continue;
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }
};
```