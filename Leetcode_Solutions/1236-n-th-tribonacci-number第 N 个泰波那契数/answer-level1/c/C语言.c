### 解题思路
最基础的动态规划

### 代码

```c
int tribonacci(int n){
    int dp[38];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i < 38; i++) {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }
    return dp[n];
}
```