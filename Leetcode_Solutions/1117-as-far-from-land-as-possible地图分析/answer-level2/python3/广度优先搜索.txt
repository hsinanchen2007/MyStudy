一 算法思路
特殊情况：当全为陆地或海洋时，结果为-1。
用二维数组dist记录各点到离其最近的陆地距离，显然所有陆地（自己到自己）距离为0。将这些陆地坐标如队列，以之为基础进行广度优先搜索，由近及远逐步计算各海洋点到陆地的距离，最后一个得到的即为所求。
二 算法实现
```python3 []
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:      
        n = len(grid)        
        dist = [[-1 for _ in range(n)] for _ in range(n)]        
        
        q = collections.deque()
        ss = 0
        total = n * n
        
        for i in range(n):
            for j in range(n):
                if grid[i][j]:
                    dist[i][j] = 0
                    q.append((i, j))
                    ss += 1
        
        if ss == total or ss == 0:
            return -1
        
        while q:
            x, y = q.popleft()
            for i, j in [(x+1, y), (x-1, y), (x, y+1), (x, y-1)]:
                if 0 <= i < n and 0 <= j < n and dist[i][j] == -1:
                    dist[i][j] = 1 + dist[x][y]
                    ss += 1
                    if ss == total:
                        return dist[i][j]
                    q.append((i, j))
```



