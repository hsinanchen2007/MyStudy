### 解题思路
回溯 + 剪枝

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        traceback(res, tmp, nums, used);
        return res;
    }

    void traceback(vector<vector<int>>& res, vector<int>& tmp, vector<int>& nums, vector<bool> used) {
        if (tmp.size() == nums.size()) {
            res.push_back(tmp);
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (used[i]) {
                    continue;
                }
                if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) {
                    continue;
                }
                used[i] = true;
                tmp.push_back(nums[i]);
                traceback(res, tmp, nums, used);
                tmp.pop_back();
                used[i] = false;
            }
        }
    }
};
```