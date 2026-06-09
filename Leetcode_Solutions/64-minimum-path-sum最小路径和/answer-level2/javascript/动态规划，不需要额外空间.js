### 解题思路

大家好，我是 17

空间可以复用 传入的grid，这样可以用二维动态规划，而不需要额外空间

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function (grid) {
  cost M = grid.length;
  cost N = grid[0].length
  //初始化行
  for (let j = 1; j < N; j++) {
    grid[0][j] = grid[0][j - 1] + grid[0][j]
  }
  //初始化列
  for (let i = 1; i < M; i++) {
    grid[i][0] = grid[i - 1][0] + grid[i][0]
  }
  //递推求解
  for (let i = 1; i < M; i++) {
    for (let j = 1; j < N; j++) {
      grid[i][j] = Math.min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j]
    }
  }
  //最后一个就是右下角的值
  return grid[[M - 1]][N - 1]
};
```