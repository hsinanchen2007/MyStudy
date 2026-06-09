### 解题思路
![image.png](https://pic.leetcode-cn.com/1afe27778547cceba538931b64c5c0c750795ebf3b15b32ad260b3ef87777262-image.png)
```
// base case
dp[0][0] = grid[i][j]

// dp转换方程
dp[i][j] = Math.max(
  dp[i - 1][j] + grid[i][j],
  dp[i][j - 1] + grid[i][j]
)
// 注意一些边缘情况
i === 0 或者 j === 0的情况
```


### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxValue = function(grid) {
  if (!grid[0] || !grid[0].length) return 0
  const dp = Array(grid.length).fill([])

  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[0].length; j++) {
      if (i === 0 && j === 0) {
        dp[i][j] = grid[i][j]
        continue
      }
      if (i === 0) {
        dp[i][j] = dp[i][j - 1] + grid[i][j]
        continue
      }
      if (j === 0) {
        dp[i][j] = dp[i - 1][j] + grid[i][j]
        continue
      }
      dp[i][j] = Math.max(
        dp[i - 1][j] + grid[i][j],
        dp[i][j - 1] + grid[i][j]
      )
    }
  }
  return dp[grid.length - 1][grid[0].length - 1]
}

```