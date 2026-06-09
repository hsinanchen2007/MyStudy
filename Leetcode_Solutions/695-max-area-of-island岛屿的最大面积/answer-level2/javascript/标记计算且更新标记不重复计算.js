```
var maxAreaOfIsland = function(grid) {
  function getArea (grid, row, column) {
    if (grid[row] && grid[row][column] === 1) {
      grid[row][column] = 0
      return 1 + getArea(grid, row + 1, column) + getArea(grid, row, column + 1) + getArea(grid, row - 1, column) + getArea(grid, row, column - 1)
    } else {
      return 0
    }
  }
  let res = 0
  for (let i = grid.length - 1; i >= 0; --i) {
    for (let j = grid[0].length - 1; j >= 0; --j) {
      if (grid[i][j] === 1) {
        const area = getArea(grid, i, j)
        res = area > res ? area : res
      }
    }
  }
  return res
};
```
