参考了[@ezoixx130](/u/ezoixx130/)的C++双端队列解法，将其翻译为Python3，代码如下：

```python
class Solution:
    class Node:
        def __init__(self, x, y, d):
            self.x = x
            self.y = y
            self.d = d

    def minCost(self, grid: List[List[int]]) -> int:
        dx, dy = [0, 0, 0, 1, -1], [0, 1, -1, 0, 0]
        m, n = len(grid), len(grid[0])
        visit = [[False] * n for i in range(m)]
        q = [self.Node(0, 0, 0)]

        def can(px, py):
            return 0 <= px < m and 0 <= py < n and not visit[px][py]

        while len(q):
            now = q.pop(0)
            x, y = now.x, now.y
            if x == m - 1 and y == n - 1:
                return now.d
            visit[x][y] = True
            nx, ny = x + dx[grid[x][y]], y + dy[grid[x][y]]
            if can(nx, ny):
                q.insert(0, self.Node(nx, ny, now.d))
            for i in range(1, 5):
                if i == grid[x][y]:
                    continue
                ax, ay = now.x + dx[i], now.y + dy[i]
                if can(ax, ay):
                    q.append(self.Node(ax, ay, now.d + 1))

        return -1
```
![QQ20200301-143027@2x.png](https://pic.leetcode-cn.com/978aa4545ca753a1e8d934f0084b25ffcbc6443d1a39b9ab8df9cb4c05426eb0-QQ20200301-143027@2x.png)
