### 解题思路
此处撰写解题思路

### 代码

```c
/*
类似与走楼梯，走1，4，9，6
类似于coinChange的动态规划可以又1，4，9，6
dp[i] = min(dp[i], dp[i-j*j] + 1);
*/
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int dp[10000];
int numSquares(int n){
    int i, j;
    dp[0] = 0;
    for (i = 1; i <= n; i++) {
        dp[i] = 32768;
        for (j = 1; j*j <= i; j++) {
            dp[i] = MIN(dp[i], dp[i-j*j] + 1);
        }
    }
    return dp[n];
}
```