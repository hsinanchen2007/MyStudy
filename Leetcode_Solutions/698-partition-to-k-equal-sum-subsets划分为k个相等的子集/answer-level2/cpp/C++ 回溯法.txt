把候选数组从大到小排序，这一步至关重要
能不能满足条件主要是大数决定的，先考虑大数，后考虑小数，能避免很多不必要的逻辑分支
```
class Solution {
public:
    bool backtrace(const vector<int>& nums, vector<int>& sums, int i, int k, int s) {
        if (i == nums.size()) return true;
        for (int j = 0; j < k; ++j) {
            if (sums[j] < s && nums[i] + sums[j] <= s) {
                sums[j] += nums[i];
                if (backtrace(nums, sums, i + 1, k, s)) {
                    return true;
                }
                sums[j] -= nums[i];
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % k != 0) return false;
        // 从大到小排序，这一步至关重要
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> sums(k, 0);
        return backtrace(nums, sums, 0, k, s / k);
    }
};
```

![image.png](https://pic.leetcode-cn.com/01f55d3030b0032acfa6728e47d5f11c231881f90f4e5da46f8978eebe255318-image.png)
