
```
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        maxI, maxJ = len(grid),len(grid[0])
        nOffsetS = [[0,1],[0,-1],[1,0],[-1, 0]]
        que = []
        time = 0        
        for i,orianges in enumerate(grid):
            for j, orange  in enumerate(orianges):
                if (orange == 2):que.append([i,j,0])                    
        while (que):
            i,j,distance = que[0][0],que[0][1],que[0][2]
            for nOffset in nOffsetS:
                nI,nJ = nOffset[0]+i,nOffset[1]+j 
                if (0 <= nI <maxI) and (0 <= nJ <maxJ) and (grid[nI][nJ] == 1):
                    grid[nI][nJ] = 2
                    que.append([nI,nJ,distance+1])
            time = distance
            que.pop(0)
        for i in grid:
            if (1 in i):
                return -1
        return time
```
