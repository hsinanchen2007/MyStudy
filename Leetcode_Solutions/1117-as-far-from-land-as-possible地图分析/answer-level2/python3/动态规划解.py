### 解题思路
动态规划

### 代码

```python3
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        from collections import deque
        n = len(grid)
        ans = 0
        distance = [[float('inf') for j in range(n)] for i in range(n)]
        
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    distance[i][j] = 0
                else:
                    if i - 1 >= 0:
                        distance[i][j] = min(distance[i][j],distance[i - 1][j] + 1)
                    if j - 1 >= 0 :
                        distance[i][j] = min(distance[i][j],distance[i][j - 1] + 1)
        for i in range(n-1,-1,-1):
            for j in range(n-1,-1,-1):
                if grid[i][j] == 0:
                    if i + 1 < n:
                        distance[i][j] = min(distance[i][j],distance[i + 1][j] + 1)
                    if j + 1 < n :
                        distance[i][j] = min(distance[i][j],distance[i][j + 1] + 1)
                    if ans < distance[i][j] :
                        ans = distance[i][j]
        if ans == 0 or ans == float('inf'):
            return -1
        return ans
```