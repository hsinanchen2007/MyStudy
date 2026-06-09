### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {boolean}
 */
var hasValidPath = function(grid) {
  let rows = grid.length
  let cols = grid[0].length
  let dirs = [
    [0, 1],
    [0, -1],
    [-1, 0],
    [1, 0]
  ] // 右，左，上 下
  let pipe = [
    [],
    [0, 1, -1, -1],
    [-1, -1, 2, 3],
    [3, -1, 1, -1],
    [-1, 3, 0, -1],
    [2, -1, -1, 1],
    [-1, 2, -1, 0]
  ]
  let type = grid[0][0]
  let stack = []
  for (let i = 0; i < 4; i++) {
    let outdir = pipe[type][i]
    if (outdir !== -1) stack.push([0, 0, outdir])
  }
  while (stack.length) {
    let [x, y, dir] = stack.pop()
    if (x === rows - 1 && y === cols - 1) return true
    let [newX, newY] = [x + dirs[dir][0], y + dirs[dir][1]]
    if (newX < 0 || newY < 0 || newX >= rows || newY >= cols) continue
    let type = grid[newX][newY]
    let outdir = pipe[type][dir]
    if (outdir !== -1) stack.push([newX, newY, outdir])
  }
  return false
}
```