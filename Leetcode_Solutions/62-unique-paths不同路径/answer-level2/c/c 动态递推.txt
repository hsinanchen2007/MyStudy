### 解题思路
此处撰写解题思路

### 代码

```c
int dp[100][100];
int uniquePaths(int m, int n){
    int i;
    int j;
    for (i = 0; i < m; i++) {
        dp[i][0] = 1;
    }
    for (i = 0; i < n; i++) {
        dp[0][i] = 1;
    }
    for (i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}
```