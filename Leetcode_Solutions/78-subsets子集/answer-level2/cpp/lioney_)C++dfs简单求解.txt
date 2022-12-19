```
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty()) return {};
        vector<int> tmp;
        vector<vector<int>> res;
        dfs(nums, tmp, 0, res);
        return res;
    }
    void dfs(vector<int>& nums, vector<int> tmp, int cur, vector<vector<int>>& res) {
        res.push_back(tmp);
        for(int i=cur; i<nums.size(); i++) {
            tmp.push_back(nums[i]);
            dfs(nums, tmp, i+1, res);
            tmp.pop_back();
        }
    }
};
```
