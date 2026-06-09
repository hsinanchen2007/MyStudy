dp[i]是前i个数字的和，然后从前往后当遇到索引i大于k的时候，计算i-k到i之间的和最大即可。
由于dp数组保存了前面的和，i-k到i区间的和等于dp[i] - dp[i-k]。
时间复杂度O(n)
```
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int dp[30002] = {0};
        if(nums.size() == 1)
            return nums[0];
        dp[1] = nums[0];
        double max_sum = INT_MIN;
        if( k == 1)
            max_sum = nums[0];
        for( int i = 2; i <= nums.size(); i++)
        {
            dp[i] = dp[i-1] + nums[i-1];
            if( i >= k && dp[i] - dp[i-k] > max_sum)
                max_sum = dp[i] - dp[i-k];
        }
        return max_sum/k;
    }
};
```
