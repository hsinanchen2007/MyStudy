### 解题思路
此处撰写解题思路

### 代码

```python3
import heapq

class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        if not heightMap or not heightMap[0]:
            return 0

        m, n = len(heightMap), len(heightMap[0])
        heap = []
        visited = set()
        directions = [(1,0), (0,1), (-1,0), (0,-1)]
        res = 0

        for i in range(m):
            for j in range(n):
                if i == 0 or j == 0 or i == m-1 or j == n-1:
                    heapq.heappush(heap, (heightMap[i][j], i, j))
                    visited.add((i, j))
        
        while heap:
            bar = heapq.heappop(heap)

            for (delta_x, delta_y) in directions:
                next_x, next_y = bar[1] + delta_x, bar[2] + delta_y
                if self.is_valid(next_x, next_y, m, n, visited):
                    res += max(0, bar[0] - heightMap[next_x][next_y])
                    heapq.heappush(heap, (max(bar[0], heightMap[next_x][next_y]), next_x, next_y))
                    visited.add((next_x, next_y))
        
        return res
    
    def is_valid(self, x, y, m, n, visited):
        return x >= 0 and x <= m-1 and y >= 0 and y <= n-1 and (x, y) not in visited
```