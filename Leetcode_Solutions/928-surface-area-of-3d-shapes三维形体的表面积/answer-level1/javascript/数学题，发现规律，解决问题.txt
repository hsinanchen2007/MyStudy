### 解题思路
1.  把每个单元格中的 方格看成一个整体，整体的面积上`4*i+2`,i是小正方体个数。即 `[[2]] = 4*2+2 = 10` , `[[3]] = 4*3+2 = 14`,但是注意过滤掉0，因为[[0]]=0.
2. 计算第一步中每个小整体，与前后左右的，和其他整体的接触面数。即当前的小正方体数目，和邻近的小正方体数目的最小值，减少的面积就是2倍的接触的面数。
 每个整体接触面都计算完了，记得给个标记，防止重复计算。 如 [[2,3]] ,2与3的接触面就是Math.min(2,3) =2,要减少的面积就是 4。 

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function (grid) {
  // 4i+2
  if (grid.length === 0 || grid[0].length === 0) return 0;
  let res = 0
  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[0].length; j++) {
      // 跳过为0的格子
      if (grid[i][j] === 0) continue;
      res += 4 * grid[i][j] + 2
      // 判断 上 下 左 右有没有物块接触
      // 上
      if (i - 1 >= 0 && grid[i - 1][j] !== "#") {
        res -= 2 * Math.min(grid[i - 1][j], grid[i][j])
      }
      //下
      if (i + 1 < grid.length && grid[i + 1][j] !== "#") {
        res -= 2 * Math.min(grid[i + 1][j], grid[i][j])
      }
      //左
      if (j - 1 >= 0 && grid[i][j - 1] !== "#") {
        res -= 2 * Math.min(grid[i][j - 1], grid[i][j])
      }
      // 右
      if (j + 1 < grid[0].length && grid[i][j + 1] !== "#") {
        res -= 2 * Math.min(grid[i][j + 1], grid[i][j])
      }
      grid[i][j] = "#"
    }
  }
  return res
};
```