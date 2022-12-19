1. 在边界上的岛屿不是孤立的岛屿 可以认为是海水
2. 与边界上的岛屿相邻的岛屿也不是孤立的岛屿 可以认为是海水
3. 剩下的都是孤立岛屿 使用深度优先遍历就可以了 
4. 找到孤立岛屿之后的将这座孤立岛屿认为是海水 下次深度优先遍历的时候就不会访问到
5.  因此每座岛屿只访问一次
```
var closedIsland = function (grid) {
  let _y = grid.length - 1;
  let _x = grid[0].length - 1;
  let dfs = function (y, x) {
    if (grid[y][x] === 0) {
      grid[y][x] = 1;
      if (y > 0) dfs(y - 1, x);
      if (y < _y) dfs(y + 1, x);
      if (x > 0) dfs(y, x - 1);
      if (x < _x) dfs(y, x + 1);
    }
  }
  for (let y = 0; y <= _y; ++y) {
    dfs(y, 0)
    dfs(y, _x)
  }
  for (let x = 1; x < _x; ++x) {
    dfs(0, x)
    dfs(_y, x)
  }
  let res = 0;
  for (let y = 1; y < _y; ++y) {
    for (let x = 1; x < _x; ++x) {
      if (grid[y][x] === 0) {
        ++res
        dfs(y, x);
      }
    }
  }
  return res;
};
```
