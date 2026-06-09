从陆地开始一层层向外扩散
```
class Solution:
    def maxDistance(self, grid) -> int:
        n = len(grid)
        depth = -1
        visited = set()
        que = [(i, j) for i in range(n) for j in range(n) if grid[i][j]]
        if not que or len(que) == n * n:
            return depth
        while que:
            depth += 1
            nodes, que = que[:], []
            for node in nodes:
                for i, j in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                    x, y = node[0] + i, node[1] + j
                    if 0 <= x < n and 0 <= y < n and not grid[x][y] and (x, y) not in visited:
                        visited.add((x, y))
                        que.append((x, y))
        return depth
```
