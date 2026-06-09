### 解题思路
dfs + set去重

### 代码

```cpp
class Solution {
public:
    void dfs(int step, set<vector<int>>&res, vector<int> t, vector<int> nums)
    {
        
        if(t.size() >= 2)
            res.insert(t);
        for(int i = step; i < nums.size(); i++)
        {
            if(t.size() > 0 && t.back() > nums[i])
                continue;
            t.push_back(nums[i]);
            dfs(i + 1, res, t, nums);
            t.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        vector<vector<int>> ans;
        vector<int> t;
        dfs(0, res, t, nums);
      
        for (auto v : res) 
        ans.push_back(v);
        return ans;
    }
    
};
```