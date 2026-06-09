- 首先初始化 1 代表线  或者代表以及当前节点已经被访问过
- 每个未被访问的节点向 上下左右  四个方向继续访问  并且标记当前节点已经被访问
```
var regionsBySlashes = function(grid) {
  let len = grid.length;
  let dp = Array.from({length: 3 * len}, () => new Array(3 * len).fill(0))
  for (let y = 0; y < len; ++y) {
    for (let x = 0; x < len; ++x) {
      if (grid[y][x] === '/') {
        dp[3*y + 2][3*x] = 1
        dp[3*y + 1][3*x + 1] = 1
        dp[3*y][3*x + 2] = 1
      } else if (grid[y][x] === '\\') {
        dp[3*y][3*x] = 1
        dp[3*y + 1][3*x + 1] = 1
        dp[3*y + 2][3*x + 2] = 1
      }
    }
  }
  let res = 0;
  len = len * 3 - 1;
  let dfs = function(y, x) {
    if (dp[y][x] === 0) {
      dp[y][x] = 1;
      if (y > 0) dfs(y-1, x);
      if (y < len) dfs(y+1, x);
      if (x > 0) dfs(y, x-1);
      if (x < len) dfs(y, x+1);
    }
  }
  for (let y = 0; y <= len; ++y) {
    for (let x = 0; x <= len; ++x) {
      if (dp[y][x] === 0) {
        ++res;
        dfs(y, x);
      }
    }
  }
  return res;
};
```
