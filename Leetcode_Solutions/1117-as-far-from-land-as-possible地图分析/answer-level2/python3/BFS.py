

### 代码

```python3
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:

        # 地图规模
        n, m = len(grid), len(grid[0])
        # 每个点到陆地的曼哈顿距离
        dist = [[float('inf') for _ in range(m)] for _ in range(n)]
        # 该点是否被访问过
        visited = [[False for _ in range(m)] for _ in range(n)]
        # 队列
        q = []
        # 陆地计数
        cnt = 0
        ans = 0
        tot = n * m
        for i in range(n):
            for j in range(m):
                if grid[i][j]:
                    dist[i][j] = 0
                    visited[i][j] = True
                    q.append((i, j))
                    cnt += 1
        # 如果都是陆地或者都是海洋，则返回-1
        if cnt == tot or cnt == 0:
            return -1
        while q:
            x, y = q.pop(0) # 出列
            for i, j in [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]:
                # 如果坐标合法并且没被访问过
                if 0 <= i < n and 0 <= j < m and not visited[i][j]:
                    dist[i][j] = min(dist[i][j], dist[x][y] + 1) # 取最小值
                    ans = max(ans, dist[i][j]) # 更新答案
                    visited[i][j] = True
                    q.append((i, j)) # 入列
        return ans

```