01背包准确值解法

```
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto n : nums) {
            sum += n;
        }
        if (sum % 2 != 0) {
            return false;
        }
        int target = sum /2;
        vector<int> dp = vector<int>(target+1, INT_MIN);
        dp[0] = 0;
        for (int i=0; i<nums.size(); i++) {
            int n = nums[i];
            for (int j=target; j>=n; j--) {
                dp[j] = max(dp[j], dp[j - n] + n); //使用了滚动数组
                if (dp[j] < 0) {
                    dp[j] = INT_MIN;
                }
            }
        }
        return dp.back() == target;
    }
};
```