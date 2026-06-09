//1.状态:楼梯阶数n  选择：1个或2个
//2.dp[i]=x 表示爬到第i阶共有x种方法
//  base case: dp[1] = 1, dp[2] = 2
//3.转移方程:dp[i] = dp[i-1] + dp[i-2]
由于这里的dp[i]只与前两个有关，所以只需要用两个变量存储进行优化就行了
```
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int dp(0), pre1(1), pre2(2);
        for(int i = 3; i <= n; ++ i) {
            dp = pre1 + pre2;
            pre1 = pre2;
            pre2 = dp;
        }
        return dp;
        
    }
};
```
