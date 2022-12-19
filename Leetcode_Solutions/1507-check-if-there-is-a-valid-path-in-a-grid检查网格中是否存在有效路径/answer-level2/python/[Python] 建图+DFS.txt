根据街道的方向建图，然后从起点开始 DFS

注意判断要去的格点能否返回到当前格点，能返回才能继续 DFS

```python
class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        n, m = len(grid), len(grid[0])

        dir4 = [[0, 1], [1, 0], [0, -1], [-1, 0]]  # 右下左上
        dir4_ids = [[0, 2], [1, 3], [1, 2], [0, 1], [2, 3], [0, 3]]  # 每种街道的两个方向所对应的 dir4 的下标
        g = [[] for _ in range(n * m)]
        for i, row in enumerate(grid):
            for j, street in enumerate(row):
                v = i * m + j
                for id in dir4_ids[street-1]:
                    d = dir4[id]  # 该街道对应的方向
                    x, y = i + d[0], j + d[1]
                    if 0 <= x < n and 0 <= y < m:
                        g[v].append(x * m + y)  # 如果能走到，连一条单向边

        vis = [False] * n*m
        def dfs(v):
            if v == n*m-1:  # 走到了终点
                return True
            vis[v] = True
            for w in g[v]:
                if not vis[w] and v in g[w] and dfs(w):  # 要去的格点没有访问过，并且能返回到当前格点，则递归下去
                    return True
            return False
        return dfs(0)
```
