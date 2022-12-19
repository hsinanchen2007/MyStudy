1. 动态规划
- dp[i]表示以i结尾时，连续子数组的最大值
- 动态方程：若dp[i-1]<=0, 则dp[i]的最大值一定为nums[i]，因为任何数加上一个非正数都会小于等于它本身，若dp[i] >0, 则dp[i]的最大值等于dp[i-1] + nums[i];
- 最后得到一个数组，数组里的最大值即为解。
```C++ []
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return INT_MIN;
        int len = nums.size();
        int dp[len];
        dp[0] = nums[0];
        int max_sum = dp[0];
        for(int i=1; i<len; i++)
        {
            if(dp[i-1] <= 0)
                dp[i] = nums[i];
            else
                dp[i] = dp[i-1] + nums[i];
             max_sum = max(max_sum, dp[i]);
        }
        return max_sum;

    }
};
```
2. 动态规划的优化
- 每一个数都只由其前一个数得到，因此采用一个变量即可
```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return INT_MIN;
        int len = nums.size();
        int cur_sum = 0;
        int max_sum = INT_MIN;
        for(int i=0; i<len; i++)
        {
            if(cur_sum <= 0)
                cur_sum = nums[i];
            else
                cur_sum = cur_sum + nums[i];
             max_sum = max(max_sum, cur_sum);
        }
        return max_sum;

    }
};
```

