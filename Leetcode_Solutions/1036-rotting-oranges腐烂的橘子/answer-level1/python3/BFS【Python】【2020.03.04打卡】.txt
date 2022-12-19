### 思路

**BFS**

```
先统计新鲜橘子个数 fresh，并把腐烂橘子个数放在队列 q 中。
遍历 q，每次弹出队首元素，判断四周有没有新鲜橘子，并变为腐烂，同时加入队列 q，fresh 减 1。
当 q 为空时表示已经全部腐烂。
每次遍历都要判断是否还有新鲜橘子剩余，如果没有新鲜橘子剩余，直接返回 minute。
最后结束遍历，还要单独判断是否有新鲜橘子剩余（防止出现类似示例 2 这种永远不会腐烂的橘子的情况）。
```

**时间复杂度:** O(n\*m)，n 为行数，m 为列数。
**空间复杂度:** O(n\*m)，n 为行数，m 为列数。

##### Python3代码

```python
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        fresh = 0
        q = []

        # count fresh oranges and enqueue rotten oranges
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    fresh += 1
                elif grid[i][j] == 2:
                    q.append((i, j))
        
        if fresh == 0:
            return 0
        dirs = [(0, 1), (0, -1), (-1, 0), (1, 0)]
        minute = 0
        
        # bfs
        while q:
            if fresh == 0:
                return minute
                
            size = len(q)
            for i in range(size):
                x, y = q.pop(0)
                for d in dirs:
                    nx, ny = x + d[0], y + d[1]
                    if nx < 0 or nx >= n or ny < 0 or ny >= m or grid[nx][ny] != 1:
                        continue
                    grid[nx][ny] = 2
                    q.append((nx, ny))
                    fresh -= 1
            minute += 1

        if fresh != 0:
            return -1
```

### 代码地址

[GitHub链接](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/0994-Rotting-Oranges/0994.py)