### 解题思路

第一步：根据 grid 初始化并查集，所有为 1 的都初始化为小的岛屿
第二步：遍历 grid 合并岛屿
第三步：遍历 并查集 得到最大岛屿

### 代码

```javascript
var maxAreaOfIsland = function(grid) {
  if (!grid.length) return 0
  // 初始化并查集
  let uf = new UninFind(grid)

  let rows = grid.length
  let cols = grid[0].length
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      if (grid[i][j] === 0) continue
      // 相邻岛屿合并
      if (i + 1 < rows && grid[i + 1][j] === 1)
        uf.union(i * cols + j, (i + 1) * cols + j)
      if (j + 1 < cols && grid[i][j + 1] === 1)
        uf.union(i * cols + j, i * cols + j + 1)
    }
  }
  return uf.max()
}

// 根据 grid 创建并查集
function UninFind(grid) {
  let rows = grid.length
  let cols = grid[0].length
  this.arr = Array(rows * cols + 1).fill(rows * cols)

  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      if (grid[i][j] === 1) this.arr[i * cols + j] = -1
    }
  }
}

UninFind.prototype.find = function(x) {
  if (this.arr[x] < 0) return x
  return this.find(this.arr[x])
}

UninFind.prototype.union = function(x, y) {
  let xparent = this.find(x)
  let yparent = this.find(y)
  // 如果已经属于同一个岛屿，直接退出
  if (xparent === yparent) return
  // 不属于同一岛屿，实现合并
  let xSize = this.arr[xparent]
  let ySize = this.arr[yparent]
  if (xSize < ySize) {
    this.arr[xparent] = yparent
    this.arr[yparent] = ySize + xSize
  } else {
    this.arr[yparent] = xparent
    this.arr[xparent] = ySize + xSize
  }
}

// 遍历得到最大岛屿值
UninFind.prototype.max = function() {
  let max = 0
  let len = this.arr.length
  for (let i = 0; i < len; i++) {
    if (this.arr[i] < 0) max = Math.max(-this.arr[i], max)
  }
  return max
}
```