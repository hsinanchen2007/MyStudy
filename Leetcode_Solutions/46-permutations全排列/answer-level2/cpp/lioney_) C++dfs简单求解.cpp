```
class Solution {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        dfs(num, 0,  res);
        return res;
    }
    void dfs(vector<int> nums, int level, vector<vector<int>>& res) {
        if (level == nums.size()) {res.push_back(nums); }
        for (int i = level; i < nums.size(); ++i) {
            swap(nums[i], nums[level]);
            dfs(nums, level + 1, res);
            swap(nums[i], nums[level]);
        }
    }
};
```
