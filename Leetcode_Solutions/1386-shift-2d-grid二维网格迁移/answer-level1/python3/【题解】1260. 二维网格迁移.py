**方法一：找出第一个元素的最终位置**

如果我们能够找出网络 `grid` 中最左上角的元素在迁移 `k` 次之后的最终位置，那么我们就可以从该位置开始，按照行优先的顺序依次填入 `grid` 中的元素。如果填到了结果的右下角，那么从结果的左上角开始继续填入元素。

在迁移了 `k` 次后，`grid` 中最左上角的数会移动到位置 `(k / m, k % m)`，注意其行坐标可能会超过总行数 `n`，因此真正的位置为 `((k / m) % n, k % m)`。那么我们从这个位置开始，按照行优先的顺序依次填入 `grid` 中的元素即可。

```Python [sol1]
class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        n, m = len(grid), len(grid[0])
        sx, sy = (k // m) % n, k % m
        g = [[0] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                g[sx][sy] = grid[i][j]
                sy += 1
                if sy == m:
                    sy = 0
                    sx += 1
                    if sx == n:
                        sx = 0
        return g
```

**复杂度分析**

- 时间复杂度：$O(MN)$。

- 空间复杂度：$O(1)$。这里只计入存储返回值之外的额外空间复杂度。