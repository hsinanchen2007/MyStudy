### 思路：
- 把初始烂掉橘子的坐标放入栈`q`同时数出初始新鲜橘子的个数`newFresh`。
- 进行循环直到最终一轮的`q`已空或者新鲜橘子都已被感染：
  - 在当前`q`中还有元素时，用此轮所有烂橘子感染其他新鲜橘子直到这轮的所有坏橘子完成感染。
  - 每次`q`中所有烂橘子完成这一分钟的感染后进行`minutes++`，并更新`q`为储存着新一轮要进行感染的烂橘子坐标的`newQ`。
  - 要注意感染函数`infectOthers()`应控制坐标不越界，同时也要随时更新剩余的新鲜橘子个数。
- 分情况返回`-1`或者总分钟数。
### 代码：
```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function (grid) {
  let q = [];
  let newFresh = 0;
  let minutes = 0;
  // Push rotten oranges to the stack and count fresh oranges
  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[i].length; j++) {
      if (grid[i][j] === 2) q.push([i, j]);
      if (grid[i][j] === 1) newFresh++;
    }
  }

  while (q.length && newFresh) {
    let newQ = []; // queue for next minute
    while (q.length) {
      let badOrange = q.shift();
      let newRottens = infectOthers(grid, badOrange[0], badOrange[1], newQ);
      newFresh -= newRottens;
    }
    minutes++;
    q = newQ;
  }
  if (newFresh !== 0) return -1;
  return minutes;
};

// Infect surrounding oranges
// Return the number of newly infected oranges
var infectOthers = function (grid, i, j, q) {
  let infected = 0;
  if (i > 0 && grid[i - 1][j] === 1) {
    grid[i - 1][j]++;
    infected++;
    q.push([i - 1, j]);
  }
  if (j > 0 && grid[i][j - 1] === 1) {
    grid[i][j - 1]++;
    infected++;
    q.push([i, j - 1]);
  }
  if (i < grid.length - 1 && grid[i + 1][j] === 1) {
    grid[i + 1][j]++;
    infected++;
    q.push([i + 1, j]);
  }
  if (j < grid[0].length - 1 && grid[i][j + 1] === 1) {
    grid[i][j + 1]++;
    infected++;
    q.push([i, j + 1]);
  }

  return infected;
}
```