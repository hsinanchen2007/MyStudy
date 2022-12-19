- grid[y][x] *= -1 表示该节点已经访问过来
- 四个方向访问完了以后 再执行一次 grid[y][x] *= -1 用于回溯
- 选择起点时 如果起点上下两个方向 或者左右两个方向都有矿 则不可能是最佳起点
```
var getMaximumGold = function (grid) {
  let _y = grid.length - 1;
  let _x = grid[0].length - 1;
  let sum = 0;
  let dfs = function (y, x, temp) {
    if (grid[y][x] > 0) {
      temp += grid[y][x];
      sum = Math.max(temp, sum);
      grid[y][x] *= -1;
      if (y > 0) dfs(y - 1, x, temp)
      if (x > 0) dfs(y, x - 1, temp)
      if (y < _y) dfs(y + 1, x, temp)
      if (x < _x) dfs(y, x + 1, temp)
      grid[y][x] *= -1;
    }
  }
  for (let y = 0; y <= _y; ++y) {
    for (let x = 0; x <= _x; ++x) {
      if (!((y > 0 && grid[y - 1][x] && y < _y && grid[y + 1][x]) || (x > 0 && grid[y][x - 1] && x < _x && grid[y][x + 1]))) {
        dfs(y, x, 0);
      }
    }
  }
  return sum;
};
```
