一维DP和二维DP思路均可解决此问题，结合背包问题，发现一个二维DP优化为一维DP的规律：

dp转移方程是**dp[i, j] = grid[i, j] + min(dp[i - 1][j], dp[i][j - 1])**

可以发现，二维DP当前状态（**dp[i, j**）需要它的上方（**dp[i, j - 1]**）和左方（**dp[i - 1, j]**）的状态决定，如果我们把**i**这一维去掉：
就变成**dp[j] = grid[i, j] + min(dp[j], dp[j - 1])**，所以这样优化是可行的的（但是要考虑边界问题dp[0]的更新），并且还是可以按顺序0...n去更新dp数组。

更一般地，假设当前状态dp[i][j]需要依赖dp[i - u][j - v]，可以有如下推测：
1. 如果u小于等于1，且如果当u=1，v=0时，可以优化为一维DP，且应顺序更新（因为需要dp[i, j - u]， 由i决定需要顺序更新）；
2. 如果u等于1，v大于等于1的时候，也可以优化为一维DP，但为了保证更新dp[i, j]时能够用到历史的状态信息，需要逆序n...0来更新dp数组（如果顺序计算，一维实现的时候，dp[i - 1, j  - 1] 会被dp[i, j  - 1]覆盖掉）；
3. 如果u大于1，那么就不能把u这个维度优化掉。

这个总结可能不全面，具体情况要看状态转移方程来决定，欢迎指正和讨论。

本题代码如下：

```

#define D2
#define CAN_USE_ORIGIN

int minPathSum(int** grid, int gridSize, int* gridColSize) {
  int m = gridSize;
  int n = gridColSize[0];
  
// Method 1: 2-D array, time O(mn), space O(n)
#ifdef D2

// Method 2: reuse grid array, time O(mn), space O(1)
#ifdef CAN_USE_ORIGIN
  int **dp = grid;  // Can use origin grid array
#else
  int dp[m][n];     // Can not use origin grid array
#endif
  
  dp[0][0] = grid[0][0];
  for (int i = 1; i < m; ++i) dp[i][0] = dp[i - 1][0] + grid[i][0];
  for (int i = 1; i < n; ++i) dp[0][i] = dp[0][i - 1] + grid[0][i];
  
  for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
      dp[i][j] = grid[i][j] + (dp[i - 1][j] > dp[i][j - 1] ? dp[i][j - 1] : dp[i - 1][j]);
    }
  }
  
  return dp[m - 1][n - 1];

// Method 3: 1-D array, time O(mn), space O(n)
#else

  int dp[n];
  dp[0] = grid[0][0];
  for (int i = 1; i < n; ++i) dp[i] = dp[i - 1] + grid[0][i];
  for (int i = 1; i < m; ++i) {  // The first row used to initialize Dp array
    for (int j = 0; j < n; ++j) {
      if (j == 0) {
        dp[j] = grid[i][j] + dp[j];
      } else {
        dp[j] = grid[i][j] + (dp[j] > dp[j - 1] ? dp[j - 1] : dp[j]);
      }
    }
  }
  return dp[n - 1];
#endif
}

```
