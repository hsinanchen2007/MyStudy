- 访问过的节点 grid[y][x]乘以负一
- 然后判断是否需要着色
- 然后依次遍历四周的四个节点
- 克隆一次grid用来保存结果 空间换时间
```
var colorBorder = function(grid, r0, c0, color) {
  let originColor = grid[r0][c0];
  if (originColor === color) return grid;
  let cloneGride = JSON.parse(JSON.stringify(grid));
  let _y = grid.length-1;
  let _x = grid[0].length-1;
  let dfs = function(y, x) {
    if (grid[y][x] !== originColor) return;
    grid[y][x] *= -1;
    if (!(x !== 0 && x !== _x && y !== 0 && y !== _y && 
      Math.abs(grid[y-1][x]) === originColor && 
      Math.abs(grid[y+1][x]) === originColor && 
      Math.abs(grid[y][x-1]) === originColor && 
      Math.abs(grid[y][x+1]) === originColor) 
      ) {
      cloneGride[y][x] = color;
    }
    if (y > 0) dfs(y-1, x);
    if (x > 0) dfs(y, x-1);
    if (x < _x) dfs(y, x+1);
    if (y < _y) dfs(y+1, x);
  }
  dfs(r0, c0)
  return cloneGride;
};
```
