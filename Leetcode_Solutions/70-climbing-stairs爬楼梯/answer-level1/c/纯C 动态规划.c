### 解题思路
动态规划 清清爽爽

### 代码

```c
int climbStairs(int n){
    /*
     * 状态方程： dp[i] = dp[i - 1] + dp[i - 2]
     * 初始条件： dp[0] = 0; dp[1] = 1; dp[2] = 2;
     */
    if (0 == n || 1 == n)
    {
        return 1; 
    }

    int* dp = (int*)malloc((n + 1) * sizeof(int));
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    int floor = 0;

    for (floor = 3; floor <= n; floor++)
    {
        dp[floor] = dp[floor - 1] + dp[floor - 2];
    }

    return dp[n];
}
```