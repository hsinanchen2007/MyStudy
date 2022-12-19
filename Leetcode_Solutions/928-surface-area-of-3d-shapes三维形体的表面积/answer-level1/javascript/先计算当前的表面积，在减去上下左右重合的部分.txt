### 解题思路
对于某一格先算出这个各的表面积(减去自己重合的但把四周重合也算上)，等于`6 * grid[i][j] - (grid[i][j] - 1) * 2`，
然后分别计算出它的上、下、左、右的个数，如果小于等于当前就减去对应正方体的个数，如果大于就减去`grid[i][j]`
求和

代码写的有点难看

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function (grid) {
  let sum = 0;
  function largerSize(current, other) {
    return current <= other ? current : other;
  }
  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[i].length; j++) {
      if (!grid[i][j]) continue;
      const current = 6 * grid[i][j] - (grid[i][j] - 1) * 2;
      let top = 0,
        bottom = 0,
        left = 0,
        right = 0;
      if (grid[i][j + 1]) top = largerSize(grid[i][j], grid[i][j + 1] || 0);
      if (grid[i - 1] && grid[i - 1][j])
        left = largerSize(grid[i][j], grid[i - 1][j] || 0);
      if (grid[i][j - 1] && grid[i][j - 1])
        bottom = largerSize(grid[i][j], grid[i][j - 1] || 0);
      if (grid[i + 1] && grid[i + 1][j])
        right = largerSize(grid[i][j], grid[i + 1][j] || 0);
      sum += current - top - bottom - left - right;
    }
  }
  return sum;
};
```