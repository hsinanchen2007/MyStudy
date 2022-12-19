####  方法1：DFS + 回溯（时间消耗很一般）

**代码：**

```python []
class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        # 不能往回走，说明开采完之后就变成0
        if not grid or not grid[0]:
            return 0

        directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        m, n = len(grid), len(grid[0])
        self.max_ = 0

        def find(visited, i, j, tmp):
            self.max_ = max(self.max_, tmp)
            for d in directions:
                if 0 <= i + d[0] < m and 0 <= j + d[1] < n:
                    if grid[i + d[0]][j + d[1]] == 0:
                        continue
                    if (i + d[0], j + d[1]) in visited:
                        continue

                    visited.add((i + d[0], j + d[1]))
                    find(visited, i + d[0], j + d[1], tmp + grid[i + d[0]][j + d[1]])
                    visited.remove((i + d[0], j + d[1]))

        for a in range(m):
            for b in range(n):
                if grid[a][b] != 0:
                    visited = {(a, b)}
                    find(visited, a, b, grid[a][b])
        return self.max_
```