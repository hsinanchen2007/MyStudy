比赛的时候没想太多，上来DFS结果超时了，原因在于没有用最优子结构去剪枝，废话不说具体思路看代码注释
``` javascript
/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number}
 */
var shortestPath = function(grid, K) {
  const xlen = grid.length;
  const ylen = grid[0].length;
  // vis 3维数组，记录到i，j位置消除k个障碍的最短距离
  const vis = [];

  for (let i = 0; i < xlen; i++) {
    vis[i] = [];
    for (let j = 0; j < ylen; j++) {
      vis[i][j] = [];
      for (let k = 0; k <= K; k++) {
        // 初始化为最大安全整数
        vis[i][j][k] = Number.MAX_SAFE_INTEGER;
      }
    }
  }
  // 记录答案
  let ans = Number.MAX_SAFE_INTEGER;
   // dfs 搜索的优化要点就是剪枝，剪枝减的好 搜索和dp一样快 i,j为当前坐标，k 为到达当前坐标消除障碍物个数，l为到达当前坐标走的距离
  function dfs(i, j, k, l) {
    // 抵达n，m
    if (i === xlen - 1 && j === ylen - 1) {
      // 消除的障碍物<=规定的K 同时取走得距离短的
      if (k <= K && ans > l) {
        ans = l;
      }
      return;
    }
    // 如果消除的障碍物多余K 或者当前走得距离比已得的最短路长则舍弃
    if (k > K || l > ans) {
      return;
    }
    // 向4个方向深搜，这里4个方向代码其实可以优化成循环，懒得做了
    if (i + 1 < xlen) {
      if (grid[i + 1][j]) {
        // 重点剪枝条件 若 vis[i+1][j][k+1]比已知到达该点的距离长，则舍弃这条路 下同
        if (vis[i + 1][j][k + 1] > l) {
          vis[i + 1][j][k + 1] = l;
          dfs(i + 1, j, k + 1, l + 1);
        }
        // 重点剪枝条件 若 vis[i+1][j][k]比已知到达该点的距离长，则舍弃这条路 下同
      } else if (vis[i + 1][j][k] > l) {
        vis[i + 1][j][k] = l;
        dfs(i + 1, j, k, l + 1);
      }
    }
    if (i - 1 >= 0) {
      if (grid[i - 1][j]) {
        if (vis[i - 1][j][k + 1] > l) {
          vis[i - 1][j][k + 1] = l;
          dfs(i - 1, j, k + 1, l + 1);
        }
      } else if (vis[i - 1][j][k] > l) {
        vis[i - 1][j][k] = l;
        dfs(i - 1, j, k, l + 1);
      }
    }
    if (j + 1 < ylen) {
      if (grid[i][j + 1]) {
        if (vis[i][j + 1][k + 1] > l) {
          vis[i][j + 1][k + 1] = l;
          dfs(i, j + 1, k + 1, l + 1);
        }
      } else if (vis[i][j + 1][k] > l) {
        vis[i][j + 1][k] = l;
        dfs(i, j + 1, k, l + 1);
      }
    }
    if (j - 1 >= 0) {
      if (grid[i][j - 1]) {
        if (vis[i][j - 1][k + 1] > l) {
          vis[i][j - 1][k + 1] = l;
          dfs(i, j - 1, k + 1, l + 1);
        }
      } else if (vis[i][j - 1][k] > l) {
        vis[i][j - 1][k] = l;
        dfs(i, j - 1, k, l + 1);
      }
    }
  }
  dfs(0, 0, 0, 0);
  return ans === Number.MAX_SAFE_INTEGER ? -1 : ans;
};
// console.log(
//   shortestPath(
//     [
//       [0, 0, 0],
//       [1, 1, 0],
//       [0, 0, 0],
//       [0, 1, 1],
//       [0, 0, 0]
//     ],
//     1
//   )
// );
// console.log(
//   shortestPath(
//     [
//       [0, 1, 1],
//       [1, 1, 1],
//       [1, 0, 0]
//     ],
//     1
//   )
// );
// console.log(
//   shortestPath(
//     [
//       [0, 1, 0, 0, 0, 1, 0, 0],
//       [0, 1, 0, 1, 0, 1, 0, 1],
//       [0, 0, 0, 1, 0, 0, 1, 0]
//     ],
//     1
//   )
// );
// console.log(
//   shortestPath(
//     [
//       [0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1],
//       [0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1],
//       [1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0],
//       [1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1],
//       [1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1],
//       [0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1],
//       [0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1],
//       [1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0],
//       [0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0],
//       [0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0],
//       [0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0]
//     ],
//     27
//   )
// );

```
