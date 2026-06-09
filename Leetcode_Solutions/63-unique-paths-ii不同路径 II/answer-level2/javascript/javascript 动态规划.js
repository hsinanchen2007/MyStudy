### 解题思路
根据62题修改即可

### 代码

```javascript
/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
    let m = obstacleGrid.length, n = obstacleGrid.length ? obstacleGrid[0].length : 0
    let dp = Array.from(new Array(m + 1), () => new Array(n + 1).fill(0))
    dp[0][0] = obstacleGrid[0][0] ? 0 : 1
    for (let i = 1; i < m; i++) {
      if (obstacleGrid[i][0] || !dp[i-1][0]){
        dp[i][0] = 0
      }else {
        dp[i][0] = obstacleGrid[i][0] ? 0 : 1
      }
    }
    for (let j = 1; j < n; j++) {
       if (obstacleGrid[0][j] || !dp[0][j-1]) {
         dp[0][j] = 0
       } else {
          dp[0][j] = obstacleGrid[0][j] ? 0 : 1
       }
    }
    for (let i = 1; i < m; i++) {
      for (let j = 1; j < n; j++) {
        if (!obstacleGrid[i][j]){
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        }
      }
    }
    return dp[m - 1][n - 1]
};
```