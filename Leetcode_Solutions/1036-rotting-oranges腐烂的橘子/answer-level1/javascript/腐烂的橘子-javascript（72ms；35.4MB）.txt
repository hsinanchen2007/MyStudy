![image.png](https://pic.leetcode-cn.com/3eccdc89105af56d16669fdb54f0f973ba78a121838c4836b90635aeddc88cb4-image.png)

每分钟遍历二维数组（遍历一次时间+1），如果grid[i][j]==2，将相邻的值==1的位置赋值为3（如果直接改为2，会导致本次赋值的值相邻位置也赋值为2），记录本次遍历橘子腐烂个数，再遍历数组将3改为2。遍历结束的条件是：没有值为1、或本轮遍历腐烂个数为0，下一轮不会再有橘子腐烂。
如果二维数组有值为1，那么返回-1；
否则，如果循环结束，count==0，返回时间-1；//只有一种情况，就是数组初始值无1
否则，返回时间。
```
function isHasGood(grid) {
  let m = grid.length,
    n = grid[0].length;
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (grid[i][j] == 1) return true;
    }
  }
}
var orangesRotting = function(grid) {
  if (grid.length == 0) return 0;
  let time = 0,
    m = grid.length,
    n = grid[0].length,
    count = 0;
  do {
    count = 0;
    for (let i = 0; i < m; i++) {
      for (let j = 0; j < n; j++) {
        if (grid[i][j] == 2) {
          j - 1 >= 0 && grid[i][j - 1] == 1 && ((grid[i][j - 1] = 3), count++); //左
          j + 1 < n && grid[i][j + 1] == 1 && ((grid[i][j + 1] = 3), count++); //右
          i - 1 >= 0 && grid[i - 1][j] == 1 && ((grid[i - 1][j] = 3), count++); //上
          i + 1 < m && grid[i + 1][j] == 1 && ((grid[i + 1][j] = 3), count++); //下
        }
      }
    }
    for (let i = 0; i < m; i++) {
      for (let j = 0; j < n; j++) {
        if (grid[i][j] == 3) {
          grid[i][j] = 2;
        }
      }
    }
    time++;
  } while (isHasGood(grid) && count !== 0);
  return isHasGood(grid) ? -1 : count == 0 ? time - 1 : time;
};
```
