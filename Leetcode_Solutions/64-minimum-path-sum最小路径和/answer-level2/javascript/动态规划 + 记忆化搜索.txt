### 解题思路
定义dp[i][j]为包含第i行第j列元素的最小路径
那么
对于普遍情况： dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + val[i][j]
以上对于i为0或j为0的边界情况做特殊处理
对于基本情况： dp[0][0] = val[0][0]

### 代码
动态规划， 无记忆化搜索会超时
```
var minPathSum = function(grid) {
  function dp (i, j) {
    if (i === 0 && j === 0) {
      return grid[0][0]
    }
    if (i === 0) {
      return dp(i, j - 1) + grid[i][j]
    }
    if (j === 0) {
      return dp(i - 1, j) + grid[i][j]
    }
    return Math.min(dp(i - 1, j), dp(i, j - 1)) + grid[i][j]
  }
  return dp(grid.length - 1, grid[0].length - 1)
};
```


记忆化搜索
```javascript
var minPathSum = function(grid) {
  const memory = {}
  function dp (i, j) {
    if (i === 0 && j === 0) {
      return grid[0][0]
    }
    if (memory[i] === undefined) {
      memory[i] = {}
    }
    if (memory[i][j] !== undefined) {
      return memory[i][j]
    }
    if (i === 0) {
      return memory[i][j] = dp(i, j - 1) + grid[i][j]
    }
    if (j === 0) {
      return memory[i][j] = dp(i - 1, j) + grid[i][j]
    }
    return memory[i][j] = Math.min(dp(i - 1, j), dp(i, j - 1)) + grid[i][j]
  }
  return dp(grid.length - 1, grid[0].length - 1)
};
```