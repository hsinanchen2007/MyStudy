合并相连区域
```
from collections import Counter
class Solution:

    def maxAreaOfIsland(self, grid: [[int]]) -> int:
        if not grid: return 0
        dx = [1,-1,0,0]
        dy = [0,0,1,-1]
        n,m = len(grid),len(grid[0])
        parent = list(range(m*n))
        seen = [[0]*m for i in range(n)]
        def union(x,y):
            parent[find(x)] = parent[find(y)]
        def find(x):
            if parent[x] == x: return x
            else: return find(parent[x])
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1 and not seen[i][j]:
                    seen[i][j] = 1
                    for x,y in zip(dx,dy):
                        if 0<=i+x<n and 0<=j+y<m and grid[i+x][j+y]==1:
                            union(i*m+j, (i+x)*m + j+y)
        A = []
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    A.append(find(i*m+j))
       # print(parent,A)
        return max(list(Counter(A).values())+[0])
```
