使用回溯方法去做DFS遍历。另外使用set去重

```
class Solution {
public:
    set<vector<int>> resSet;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> tempVector;
        _findSubsequences(nums, 0, tempVector);
        vector<vector<int>> res;
        for (auto v : resSet) {
            res.emplace_back(v);
        }
        return res;
    }
    
    void _findSubsequences(vector<int>& nums, int start, vector<int>& tempNums) {
        if (tempNums.size() > 1) {
            resSet.insert(tempNums);
        }
        for (int i=start; i<nums.size(); i++) {
            if (tempNums.size() > 0 && tempNums.back() > nums[i]) {
                continue;
            }
            tempNums.push_back(nums[i]);
            _findSubsequences(nums, i + 1, tempNums);
            tempNums.pop_back();
        }
    }
    
};
```