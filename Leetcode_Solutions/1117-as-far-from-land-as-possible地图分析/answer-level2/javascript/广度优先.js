- 与陆地在上下左右四个方向相邻的海洋距离是1
- 首先找到所有的陆地 然后找到他们四个方向相邻的海洋 并将海洋的状态变成新的陆地 
- 此时与陆地距离为1的海洋全部被找到
- 然后新的陆地又是新的起点 继续寻找与新陆地距离为1的海洋(与原始陆地距离为2)
- 直到最后无法找到海洋 停止
```
var maxDistance = function (grid) {
  let queue = [];
  let _y = grid.length - 1;
  let _x = grid[0].length - 1;
  for (let y = 0; y <= _y; ++y) {
    for (let x = 0; x <= _x; ++x) {
      if (grid[y][x]) queue.push([y, x]);
    }
  }
  let handlePoint = function (y, x, arr) {
    if (y < _y && grid[y + 1][x] === 0) {
      grid[y + 1][x] = 1
      arr.push([y + 1, x])
    }
    if (x < _x && grid[y][x + 1] === 0) {
      grid[y][x + 1] = 1
      arr.push([y, x + 1])
    }
    if (y > 0 && grid[y - 1][x] === 0) {
      grid[y - 1][x] = 1
      arr.push([y - 1, x])
    }
    if (x > 0 && grid[y][x - 1] === 0) {
      grid[y][x - 1] = 1
      arr.push([y, x - 1])
    }
  }
  if (queue.length === 0 || queue.length === (_x + 1) * (_y + 1)) return -1;
  let res = 0;
  while (queue.length) {
    let tempQueue = [];
    queue.forEach(([y, x]) => {
      handlePoint(y, x, tempQueue)
    })
    if (tempQueue.length) {
      ++res;
    }
    queue = tempQueue;
  }
  return res;
};
```
