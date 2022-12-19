```
class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        ROW, COL = len(grid), len(grid[0])
        visit = set()
        directions = ((0, 1), (0, -1), (1, 0), (-1, 0))
        
        def dfs(i, j):
            visit.add((i, j))
            di, dj = directions[grid[i][j]-1]
            if 0 <= i+di < ROW and 0 <= j+dj < COL and (i+di, j+dj) not in visit:
                dfs(i+di, j+dj)
                
        dfs(0, 0)
        cost = 0
        while (ROW-1, COL-1) not in visit:
            cost += 1
            for i, j in set(visit):
                for di, dj in directions:
                    ni, nj = i+di, j+dj
                    if 0 <= ni < ROW and 0 <= nj < COL and (ni, nj) not in visit:
                        dfs(ni, nj)
        return cost
            
```