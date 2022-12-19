```c++
class Solution {
public:
    int massage(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        //dp表示在以下标 i 结尾的之前的最大时间
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int sum = dp[0];
        for (int i = 1; i < dp.size(); i++) {
            if (i == 1) {
                dp[i] = nums[1];
            } else if (i == 2) {
                dp[i] = nums[i] + dp[0];
            } else dp[i] = fmax(dp[i - 2], dp[i - 3]) + nums[i];
            sum = fmax(sum, dp[i]);
        }
        
        return sum;
    }
};
```