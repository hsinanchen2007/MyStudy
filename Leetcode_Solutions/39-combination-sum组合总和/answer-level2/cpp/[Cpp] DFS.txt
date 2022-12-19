### 代码

```cpp
class Solution {
private:
    void helper(vector<int>& nums, int target, vector<vector<int>>& res, vector<int> tmp, int now, int ind) {
        if (now == target) {
            sort(tmp.begin(), tmp.end());
            if (find(res.begin(), res.end(), tmp) == res.end()) res.push_back(tmp);
        }
        if (now >= target) return;
        for (int i = ind; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            helper(nums, target, res, tmp, now + nums[i], i);
            tmp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        helper(candidates, target, res, tmp, 0, 0);
        return res;
    }
};
```