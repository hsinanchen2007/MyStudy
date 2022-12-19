
### 代码

```cpp
class Solution {
public:
    // 动态规划法 0ms
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> max_vals(nums.size(), 0);
        int len = (int)nums.size() - 1;
        for (int i = len; i >= 0; i--) {
            if (i == len) max_vals[i] = nums[i];
            else if (i == len - 1) max_vals[i] = std::max(nums[i], nums[i + 1]);
            else {
                max_vals[i] = std::max(max_vals[i + 1], max_vals[i + 2] + nums[i]);
            }
        }

        return max_vals[0];
    }

    // 回溯法, 超时
    void robHelp(vector<int> &nums, int st, int cur_val, int &max_val) {
        if (st >= nums.size()) return;

        for (int i = st; i < nums.size(); i++) {
            max_val = std::max(cur_val + nums[i], max_val);
            robHelp(nums, i + 2, cur_val + nums[i], max_val);
        }
    }
};
```