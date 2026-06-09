### 解题思路

一开始思路只是算行和列的下标，计算他们的位数和，但是提交后发现是错的，原因是有些位置下表和是满足了，但是根本走不到。所以还是要模拟走的过程。由于是统计所有能走到的格子，不是最大深度。就很容易想到**广度优先搜索（Breadth First Search）**。

#### 解答过程：

1. 广度优先用队列实现，需要一个访问数组visited，记录是否访问过,默认false。
2. 初始条件：队列起始位置(0,0)，访问数组visited[0][0]=true;
3. 循环条件，队列不为空，出队一个格子，判断当前出队格子是否符合要求，符合结果加1, 然后判断上下左右四个格子是否满足边界条件，满足情况下，放入队列，并把对应访问数组设置为true，以免后面重复放入队列。
4. 判断数字每个位数是否满足要求，我这边用了js的语言特性，偷了个懒

### 代码

```javascript
var movingCount = function (m, n, k) {
  let queue = [{ c: 0, r: 0 }];
  let ans = 0;
  let visited = [];
  for (var i = 0; i < m; i++) {
    visited[i] = [];
    for (var j = 0; j < n; j++) {
      visited[i][j] = false;
    }
  }
  visited[0][0] = true;

  while (queue.length) {
    let top = queue.shift();
    if (canArrive(top, k)) {
      ans++;
      if (top.r - 1 >= 0 && !visited[top.r - 1][top.c]) {
        queue.push({
          c: top.c,
          r: top.r - 1,
        });
        visited[top.r - 1][top.c] = true;
      }

      if (top.r + 1 < m && !visited[top.r + 1][top.c]) {
        queue.push({
          c: top.c,
          r: top.r + 1,
        });
        visited[top.r + 1][top.c] = true;
      }

      if (top.c + 1 < n && !visited[top.r][top.c + 1]) {
        queue.push({
          c: top.c + 1,
          r: top.r,
        });
        visited[top.r][top.c + 1] = true;
      }

      if (top.c - 1 >= 0 && !visited[top.r][top.c - 1]) {
        queue.push({
          c: top.c - 1,
          r: top.r,
        });
        visited[top.r][top.c - 1] = true;
      }
    }
  }

  return ans;
};

function canArrive(pos, k) {
  return accEveryDigit(pos.c) + accEveryDigit(pos.r) <= k;
}

function accEveryDigit(num) {
  return String(num)
    .split("")
    .reduce((no, v) => Number(v) + no, 0);
}

```