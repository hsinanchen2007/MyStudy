### 思路一：DP
由于首尾相连，所以第一个和最后一个只能抢一个或者都不抢，这里将第一个和最后一个分别去掉，各算一遍最大值，然后取两者的最大值即为所求。
在计算最大值中dp[i]表示在第i个房屋可以获得的最大值，如果当前房屋抢，则最大值为nums[i] + dp[i - 2], 如果不抢，则为dp[i - 1]。

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
        return max(helper(nums, 0, nums.size() - 1), helper(nums, 1, nums.size()));
    }

    int helper(vector<int> &nums, int left, int right) {
        if (right - left <= 1) return nums[left];
        vector<int> dp(right, 0);
        dp[left] = nums[left];
        dp[left + 1] = max(nums[left], nums[left + 1]);
        for (int i = left + 2; i < right; ++i) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[right - 1];
    }
};
```