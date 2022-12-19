### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/0bde8eb282dd2805a55892743490ca3ee255140499a8a93fae64da69604fac0d-%E6%8D%95%E8%8E%B7.PNG)
常规的dp操作，dp[i]是到第i步阶梯总共有多少种爬法，那么要求dp[i]就必须要求得dp[i-1]是多少，达到第i个台阶可以从第i-2个台阶走两步，从第i-1个台阶走一步，所以特征方程是dp[i] = dp[i-1] + dp[i-2]，而dp[1]=1,dp[2] = 2。
### 代码

```c
int climbStairs(int n){
    int i,dp[100010] = {0};
    dp[1] = 1;
    dp[2] = 2;
    for(i = 3; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
```