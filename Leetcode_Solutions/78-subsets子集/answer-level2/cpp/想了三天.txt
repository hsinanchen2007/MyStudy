### 解题思路
选 或者 不选

### 代码

```cpp
class Solution {
public:
    vector<vector<int>>res;
    vector<int> ans;
    void dfs(int pos, vector<int>& nums) {
        if (pos == nums.size()) {
            res.emplace_back(ans);
            return;
        }
        dfs(pos+1, nums);
        ans.emplace_back(nums[pos]);
        dfs(pos+1, nums);
        ans.pop_back();
    } 
    vector<vector<int>> subsets(vector<int>& nums) {
       if (nums.size() < 1) return res;
        dfs(0,nums);
        return res;
    }
};
```