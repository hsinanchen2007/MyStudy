按照题意，其实就是将新鲜橘子的个数减为0，需要几步。那么思路也就来了。
首先，把数据源补全，缺少的都为0。
其次，计算新鲜橘子的个数。如果为0，就直接输出。
然后，循环。条件是新鲜橘子的个数不等于0，然后找出所有的不新鲜的橘子，将不新鲜橘子的四周都腐烂，计数+1。当操作完，更新下当前的新鲜橘子个数，继续下一轮腐烂。 但是注意到，可能会有死循环，这个时候，就知道，次数不可能超过所有橘子的个数。当运行到所有橘子的次数时，肯定时无法处理的时候，返回-1即可。

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function(grid) {
  var freshCount = 0;
  var rLen = grid.length;
  var cLen = grid.reduce((max, v) => {
    if (v.length > max) {
      max = v.length;
    }
    return max;
  }, 0);

  for (var i = 0; i < rLen; i++) {
    if (!grid[i]) {
      grid[i] = [];
    }
    for (var j = 0; j < cLen; j++) {
      grid[i][j] = grid[i][j] || 0;
      if (grid[i][j] == 1) {
        freshCount++;
      }
    }
  }
  let times = 0;
  while (freshCount) {
    var brokeIndex = [];
    grid.forEach((list, i) => {
      list.forEach((v, j) => {
        if (v == 2) {
          brokeIndex.push({ row: i, col: j });
        }
      });
    });
    if (times >= rLen * cLen) {
      times = -1;
      break;
    }
    times++;
    brokeIndex.forEach(v => {
      let { row, col } = v;
      if (row - 1 >= 0 && grid[row - 1][col]) {
        grid[row - 1][col] = 2;
      }
      if (row + 1 < rLen && grid[row + 1][col]) {
        grid[row + 1][col] = 2;
      }
      if (col - 1 >= 0 && grid[row][col - 1]) {
        grid[row][col - 1] = 2;
      }
      if (col + 1 < cLen && grid[row][col + 1]) {
        grid[row][col + 1] = 2;
      }
    });

    freshCount = 0;
    grid.forEach(row => {
      row.forEach(v => {
        if (v == 1) {
          freshCount++;
        }
      });
    });
  }
  return times;
};

console.log(orangesRotting([[0, 2]]));

```
