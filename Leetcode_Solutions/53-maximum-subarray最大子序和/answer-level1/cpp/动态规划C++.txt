前i个数的最大连续序列和为dp[i]
前1+1个数的最大连续序列和就是dp[i+1] = max(dp[i]+nums[i+1],nums[i+1]);
如果dp[i]+nums[i+1]<nums[i+1],即dp[i]<0。
每处理一个数，就更新一下最长大连续序列和，直至处理完n个数。
举例：
序列 -2 1 -3 2
dp[0] = -2
dp[1] = 1
dp[2] = -2 ( 1 + (-3) )
dp[3] = 2
```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = int(nums.size());
        vector<int> dp(n);
        int prevmaxsum = nums[0];
        int maxsum = prevmaxsum;
        for(int i=1;i<n;i++){
            if(prevmaxsum<0)
                prevmaxsum = nums[i];
            else
                 prevmaxsum+=nums[i];
            if(maxsum<prevmaxsum) maxsum = prevmaxsum;
        }
        return maxsum;
    }
};
```

