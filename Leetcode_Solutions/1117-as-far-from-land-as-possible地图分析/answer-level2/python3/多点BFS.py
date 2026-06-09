### 解题思路
抄作业，看甜姨思路

### 代码

```python3
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        n = len(grid)
        from collections import deque
        queue = deque([(i, j) for i in range(n) for j in range(n) if grid[i][j] == 1])
        if len(queue) == 0 or len(queue) == n ** 2:
            return -1

        move = ((0, 1), (0, -1), (1, 0), (-1, 0))
        while queue:
            x, y = queue.popleft()
            for dx,dy in move:
                nx, ny = x + dx, y + dy
                if nx >= n or ny >= n or nx < 0 or ny < 0 or grid[nx][ny] != 0:
                    continue
                grid[nx][ny] = grid[x][y] + 1
                queue.append((nx, ny))  # 子节点入队，下一个循环继续遍历
        return grid[x][y] - 1
```