```
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        nextRot = []
        rotTime = 0
        unRotNum = 0
        #腐烂的橘子入队
        for i in range (len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 2:
                    nextRot.append((i,j))
                if grid[i][j] == 1:
                    unRotNum += 1


        #一轮一轮腐烂
        while len(nextRot) > 0:
            tmp = []
            for x,y in nextRot:
                if x-1 >= 0 and grid[x-1][y] == 1:
                    grid[x-1][y] = 2
                    tmp.append((x-1,y))
                if x+1 < len(grid) and grid[x+1][y] == 1:
                    grid[x+1][y] = 2
                    tmp.append((x+1,y))
                if y-1 >= 0 and grid[x][y-1] == 1:
                    grid[x][y-1] = 2
                    tmp.append((x,y-1))
                if y+1 < len(grid[x]) and grid[x][y+1] == 1:
                    grid[x][y+1] = 2
                    tmp.append((x,y+1))
            nextRot = tmp
            if len(tmp) != 0:
                rotTime+=1
        
        #检查是否有无法腐烂的橘子
        for i in range (len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 1:
                    return -1
        return rotTime
```
