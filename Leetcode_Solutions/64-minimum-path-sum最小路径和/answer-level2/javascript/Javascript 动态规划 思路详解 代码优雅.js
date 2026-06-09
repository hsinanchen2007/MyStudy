本题考察知识点：
  - 典型的动态规划类问题
  - 考察逻辑思维能力，能够通过题目意思推导出状态转移方程
  - 动态规划实际的编码功底

```javascript
/**
 * 64. Minimum Path Sum
 * https://leetcode.com/problems/minimum-path-sum/
 * @param {number[][]} grid
 * @return {number}
 */
/**
 * DP O(m*n)
 * 定义状态：求什么，什么就是状态，即 dp[i][j] 表示 从 [0, 0] 走到 [i, j] 的最小路径和
 * 确定状态转移方程：
 *  - 就是找 dp[i,j] 与 dp[i,j]的上一步 之间的关系
 *  - 因为是从左上走到右下，所以一定是从 dp[i][j] 的左边或者上边走过来的，这两个值谁小就选谁
 *  - 即 dp[i][j] += Math.min(dp[i-1][j] + dp[i][j-1])
 * 明确basecase：
 *  - 就是找找边界情况，初始条件啥的 
 *  - dp[0][0] = 0            
 *  - dp[i][0] += dp[i-1][0]  
 *  - dp[0][j] += dp[0][j-1]  
 */
const minPathSum = (grid) => {
  let rowLength = grid.length, colLength = grid[0].length
  for (let row = 0; row < rowLength; row++) {
    for (let col = 0; col < colLength; col++) {
      if (row === 0 && col === 0) continue
      if (row === 0) grid[row][col] += grid[row][col-1]
      else if (col === 0) grid[row][col] += grid[row-1][col]
      else grid[row][col] += Math.min(grid[row][col-1], grid[row-1][col])
    }
  }
  return grid[rowLength-1][colLength-1]
}
```

[更多 JS-Leetcode 题解请关注](https://github.com/dwgeneral/JS-Leetcode)