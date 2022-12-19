### 解题思路
采用动态规划的思想，用dp数组保存已经计算出的结果，避免重复计算。

### 代码

```c
int dp[1000] = {0};
int climbStairs(int n){
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    if(dp[n] != 0)
        return dp[n];
    else
        dp[n] = climbStairs(n-1) + climbStairs(n-2);
    return dp[n];
}
```