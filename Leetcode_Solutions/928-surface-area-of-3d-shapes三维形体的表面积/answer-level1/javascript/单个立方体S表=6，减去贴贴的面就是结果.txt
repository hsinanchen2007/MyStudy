解法一 相减法 O(n)
1.求出几个立方体，总面积是6*n
2.求垂直需要减去的面 (n - 1) * 2
3.求统一层邻居相邻需要减去的面：如果有邻居，就减去邻居和自身较小的值

```
var surfaceArea = function(grid) {
  if (grid === null) {
    return
  }
  
  let result = 0
  let rows = grid.length
  let cols = grid[0].length
  
  let cube = 0
  let horizon = 0
  let vertical = 0
  
  let helper = function(i, j) {
    if (i >= 0 && i < rows && j >= 0 && j < cols) {
      return grid[i][j]
    }
    
    return 0
  }
  
  let getNeighbor = function(i, j) {
    let count = 0
    count += Math.min(grid[i][j], helper(i + 1, j))
    count += Math.min(grid[i][j], helper(i - 1, j))
    count += Math.min(grid[i][j], helper(i, j + 1))
    count += Math.min(grid[i][j], helper(i, j - 1))
    
    return count
  }
  
  let getVertical = function(i, j) {
    if (grid[i][j] <= 1) {
      return 0
    } else {
      return (grid[i][j] - 1) * 2
    }
  }
  
  for (let i=0; i<rows; i++) {
    for (let j=0; j<cols; j++) {
      cube += grid[i][j]
      horizon += getNeighbor(i, j)
      vertical += getVertical(i, j)
    }
  }
  
  result = cube * 6 - horizon - vertical
  
  return result
};
```

解法2 投影法
(正面投影 + 左侧投影 + 垂直投影) * 2
但是有空心的情况，没想出来正面解决