### 解题思路

从左走起

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function(grid) {
    const m = grid.length, n = grid[0].length
    const memo = [...Array(m)].map(() => [...Array(n)])
    for (let i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (i === 0 && j === 0) { // 左上角
                memo[i][j] = grid[i][j]
            } else if (i === 0) { // 最左边只能从上往下走
                memo[i][j] = memo[i][j-1] + grid[i][j]
            } else if (j === 0) { // 最上面只能从左往右走
                memo[i][j] = memo[i-1][j] + grid[i][j]
            } else { // 左和上选最小的
                memo[i][j] = grid[i][j] + Math.min(memo[i][j-1], memo[i-1][j])
            }
        }
    }
    return memo[m - 1][n - 1]
};
```