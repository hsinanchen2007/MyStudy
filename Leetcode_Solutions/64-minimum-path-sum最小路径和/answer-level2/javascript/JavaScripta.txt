### 解题思路

动态规划

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function(grid) {
    const m = grid.length,
          n = grid[0].length;
    if (m <=0 || n <= 0) {
        return 0;
    }
    const dp = [...Array(m)].map(() => [...Array(n)]);
    dp[0][0] = grid[0][0]
    // 初始化最左边的值
    for (let i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0]
    }
    // 初始化最上面的值
    for (let i = 1; i < n; i++) {
        dp[0][i] = dp[0][i - 1] + grid[0][i]
    }
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]
        }
    }
    return dp[m - 1][n - 1]
};
```