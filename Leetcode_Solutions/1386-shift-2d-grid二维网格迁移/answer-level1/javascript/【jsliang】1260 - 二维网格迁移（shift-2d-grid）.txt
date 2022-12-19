首先，这道题如果按照题意，一次一次地迁移，估计会超时。

那么，我们可以思考下，经过 `k` 次的迁移后，这个点的位置会到哪里。

> 整体迁移情况

```
time -> 0
[ [1, 2],
  [3, 4] ]

time -> 1
[ [4, 1],
  [2, 3] ]

time -> 2
[ [3, 4],
  [1, 2] ]

time -> 3
[ [2, 3]
  [4, 1] ]

time -> 4
[ [1, 2]
  [3, 4] ]
```

从整体迁移情况可以看出，当我们的 `k === m * n` 后，我们就进行新一轮往复的迁移。

> m 为行，n 为列，以下相同

所以 `k` 需要简化成 `k % (m * n)` 次。

> 单个迁移情况

```
假设为上图的 1，迁移了 3 次后：

[0, 0] => [0, 1] => [1, 0] => [1, 1]
```

可以看到，我们可以把 `[x, y]` 看成是一个两位长度的数。

这个两位长度的数，符合满 n 进 1 的规则。

即在 `[0, 1] => [1, 0]` 的时候，其实一开始是 `[0, 1] => [0, 2]`，因为 `[0, 2]` 满足于 `2 === n` 了，所以需要 0 加一，即 `[1, 0]`。

同时，当 `[x, y]` 中的 `x` 满足于 `2 === m` 时，`x` 应该也进行加一操作。

即符合规则：`[(x + Math.floor((y + k) / n)) % m, (y + k) % n]`。

OK，如此，我们就可以得出结果：

> 找规律

```js
const shiftGrid = (grid, k) => {
  const m = grid.length;
  const n = grid[0].length;
  k = k % (m * n);
  const matrix = Array.from(Array(m), () => []);
  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[i].length; j++) {
      matrix[(i + Math.floor((j + k) / n)) % m][(j + k) % n] = grid[i][j];
    }
  }
  return matrix;
};
```

Submit 提交：

```js
Accepted
* 107/107 cases passed (108 ms)
* Your runtime beats 83.23 % of javascript submissions
* Your memory usage beats 58.7 % of javascript submissions (40.3 MB)
```

这样，我们就通过观察、分析题意，一步一步推导出结果。

如果小伙伴们还有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~

公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library