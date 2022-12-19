遇到有关序列相关的题，动态规划总可以试一下。  
状态：f(n)表示序列长度为n的最大时长。  
状态转移方程：f(n) = max(f(n-2) + a(n - 1), f(n - 1)) n>=2，根据是否选择最后一个划分为两种情况,取两种情况的最大值即可。    
初始状态：f(0) = 0,序列长度为0时;  f(1) = a(0), 序列长度为1时;  
```
class Solution {
public:
    int massage(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;

        vector dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i = 2; i <= n; i++)
        {
            dp[i] = max(dp[i-2] + nums[i - 1], dp[i - 1]);
        }

        return dp[n];
    }
};
```