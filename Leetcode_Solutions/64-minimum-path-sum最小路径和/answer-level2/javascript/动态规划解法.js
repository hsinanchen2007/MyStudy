### 解题思路
典型的动态规划，用 dp[i][j] 表示从 (i, j) 出发到 (m-1, n-1) 的最短路径。
dp[i][j] := min(dp[i+1][j], dp[i][j+1]) + grid[i][j];

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
const min = (a, b) => {
    return a < b ? a : b;
}

var minPathSum = function(grid) {
    const m = grid.length;
    if (!m) return 0;
    const n = grid[0].length;
    const dp = new Array();
    for (let i = 0; i < m; ++i) {
        const temp = new Array();
        for (let j = 0; j < n; ++j) {
            temp.push(0)
        }
        dp.push(temp);
    }
    dp[m-1][n-1] = grid[m-1][n-1];
    for (let i = m - 2; i >= 0; --i) {
        dp[i][n-1] = grid[i][n-1] + dp[i+1][n-1];
    }
    for (let j = n - 2; j >= 0; --j) {
        dp[m-1][j] = grid[m-1][j] + dp[m-1][j+1];
    }
    for (let i = m - 2; i >= 0; --i) {
        for (let j = n - 2; j >= 0; --j) {
            dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + grid[i][j];
        }
    }
    return dp[0][0];
};
```

### 复杂度
- 时间复杂度 O(M*N)
- 空间复杂度 O(M*N)