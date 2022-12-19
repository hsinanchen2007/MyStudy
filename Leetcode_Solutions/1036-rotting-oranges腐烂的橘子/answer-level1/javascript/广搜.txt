### 解题思路

首先遍历一遍，目的有两个

- 将腐烂的橘子的坐标找出来
- 记录新鲜橘子的数量

然后进行广搜，初始量是腐烂的橘子。
每搜一层，时间加一。知道都搜索完。

如果最后新鲜橘子还有，就返回 -1 。否则返回时间

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function(grid) {
    if (grid.length === 0) return 0
  const helperQueue = []
  let freshNum = 0
  const row = grid.length
  const column = grid[0].length
  for (let i = 0; i < row; i++) {
    for (let j = 0; j < column; j++) {
      if (grid[i][j] === 2) helperQueue.push([i, j])
      else if (grid[i][j] === 1) freshNum++
    }
  }
  let ans = -1
  const addItem = (i, j) => {
    if (grid[i][j] === 1) {
      helperQueue.push([i, j])
      grid[i][j] = 2
      freshNum--
    }
  }
  while (helperQueue.length !== 0) {
    ans++
    let levelNum = helperQueue.length
    while (levelNum--) {
      const [i, j] = helperQueue.shift()
      if (i + 1 < row) addItem(i + 1, j)
      if (i > 0) addItem(i - 1, j)
      if (j + 1 < column) addItem(i, j + 1)
      if (j > 0) addItem(i, j - 1)
    }
  }
  return freshNum === 0 ? (ans < 0 ? 0 : ans) : -1
};
```

### typescript

```typescript
const orangesRotting = function(grid: number[][]): number {
  if (grid.length === 0) return 0
  const helperQueue: [number, number][] = []
  let freshNum = 0
  const row = grid.length
  const column = grid[0].length
  for (let i = 0; i < row; i++) {
    for (let j = 0; j < column; j++) {
      if (grid[i][j] === 2) helperQueue.push([i, j])
      else if (grid[i][j] === 1) freshNum++
    }
  }
  let ans = -1
  const addItem = (i: number, j: number) => {
    if (grid[i][j] === 1) {
      helperQueue.push([i, j])
      grid[i][j] = 2
      freshNum--
    }
  }
  while (helperQueue.length !== 0) {
    ans++
    let levelNum = helperQueue.length
    while (levelNum--) {
      const [i, j] = helperQueue.shift() as [number, number]
      if (i + 1 < row) addItem(i + 1, j)
      if (i > 0) addItem(i - 1, j)
      if (j + 1 < column) addItem(i, j + 1)
      if (j > 0) addItem(i, j - 1)
    }
  }
  return freshNum === 0 ? (ans < 0 ? 0 : ans) : -1
}
```