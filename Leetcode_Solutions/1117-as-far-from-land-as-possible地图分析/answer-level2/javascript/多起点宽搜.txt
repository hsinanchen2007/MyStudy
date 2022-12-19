> 先写了个深搜，越写越乱，遂重写宽搜，神清气爽不少
#### 要点
- 很基础的，通过队列剪枝，即，已经在队列中准备更新的节点，不必重复入队了
- 先扫一遍地图，进行各数组的初始化
- 多起点：
    - 写深搜的时候觉得有多个大陆（即有多个起点）很难下手，改成宽搜就简单多了 ——
    - 扫地图时，遇到大陆就将该节点入队列（完）（用对方法真的很清爽）

> 顺便学习了如何用JavaScript模拟队列，即 `Array.prototype.shift()`出队， `Array.prototype.push()`入队

```JavaScript
var maxDistance = function(grid) {
  let go = [[1, 0], [-1, 0], [0, 1], [0, -1]] // 模拟往四个方向走，写入数组代码更简洁好看点
  /* que：队列
   * dis：存储每个节点的最短距离
   * flag：标记节点是否在队列中
   */
  let que = [], dis = [], flag = []
  let ans = -1
  for (let i = 0; i < grid.length; i++) {
    dis[i] = []
    flag[i] = []
  }
  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[i].length; j++) {
      if (grid[i][j] === 1) {
        dis[i][j] = 0
        que.push([i, j]) // 遇到大陆就将其push入队列
        flag[i][j] = true
      } else if (grid[i][j] === 0) {
        dis[i][j] = -1
      }
      flag[i][j] = false
    }
  }
  while (que.length > 0) { // 很标准的BFS
    let node = que.shift()
    x = node[0]
    y = node[1]
    flag[x][y] = false
    for (let i = 0; i < 4; i++) {
      let p = x + go[i][0]
      let q = y + go[i][1]
      if (p >= grid.length || q >= grid.length || p < 0 || q < 0) { // 判断是否出界
        continue
      }
      if (dis[p][q] > dis[x][y] + 1 || dis[p][q] == -1) {
        dis[p][q] = dis[x][y] + 1
        ans = dis[p][q] > ans ? dis[p][q] : ans // 更新答案
        if (!flag[p][q]) { // BFS的剪枝优化，已经在队列中的就不重复入队了
          que.push([p, q])
          flag[p][q] = true
        }
      }
    }
  }
  return ans
};
```
