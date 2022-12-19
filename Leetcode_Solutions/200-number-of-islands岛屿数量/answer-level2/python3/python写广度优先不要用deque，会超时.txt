如果用python写广度优先的方法，使用deque的append和popleft处理会超时，说明这个数据结构的数据存取效率不行啊。


```python
class Solution:
    def numIslands(self, grid) -> int:
        if not grid:
            return 0
        directions = [
            lambda node: [node[0], node[1] + 1],
            lambda node: [node[0], node[1] - 1],
            lambda node: [node[0] + 1, node[1]],
            lambda node: [node[0] - 1, node[1]]
        ]
        n = len(grid)
        m = len(grid[0])
        island_count = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1':
                    q = list()
                    q.append([i, j])
                    while q:
                        node = q[-1]
                        grid[node[0]][node[1]] = '0'
                        for direction in directions:
                            x, y = direction(node)
                            if 0 <= x < n and 0 <= y < m:
                                if grid[x][y] == '1':
                                    q.append([x, y])
                                    break
                        else:
                            q.pop()
                    island_count += 1
        return island_count
```
