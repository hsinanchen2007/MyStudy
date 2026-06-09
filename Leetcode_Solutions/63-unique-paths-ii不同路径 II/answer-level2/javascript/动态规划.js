### 解题思路
此处撰写解题思路

与 unique-paths 的不同点在于，本题多了一些障碍物,

用 dp[i][j] 表示从 (i, j) 到 (n-1, m-1) 的路径数,

- obstacleGrid[i][j] == 1，即当前格子有障碍，那么 dp[i][j] := 0
- obstacleGrid[i][j] == 0，那么 dp[i][j] := dp[i+1][j] + dp[i][j+1]


### 代码

```javascript
/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
    const n = obstacleGrid.length;
    if (!n) return 0;
    const m = obstacleGrid[0].length;
    const dp = new Array();
    for (let i = 0; i < n; ++i) {
        dp[i] = new Array();
        for (let j = 0; j < m; ++j) {
            dp[i].push(0);
        }
    }
    dp[n-1][m-1] = 1 - obstacleGrid[n-1][m-1];
    for (let i = n - 2; i >= 0; --i) {
        dp[i][m-1] = (obstacleGrid[i][m-1] || dp[i+1][m-1] === 0) ? 0 : 1;
    }
    for (let j = m - 2; j >= 0; --j) {
        dp[n-1][j] = (obstacleGrid[n-1][j] || dp[n-1][j+1] === 0) ? 0 : 1;
    }
    for (let i = n - 2; i >= 0; --i) {
        for (let j = m - 2; j >= 0; --j) {
            dp[i][j] = obstacleGrid[i][j] ? 0 : dp[i+1][j] + dp[i][j+1];
        }
    }
    return dp[0][0];
};
```

### 复杂度
- 时间复杂度：O(M*N)
- 空间复杂度：O(M*N)