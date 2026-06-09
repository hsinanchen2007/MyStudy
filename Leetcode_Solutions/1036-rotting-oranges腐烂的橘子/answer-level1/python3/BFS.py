
# 服了
BFS都能成简单题就离谱。
```
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        # BFS
        dx = [1,-1,0,0]
        dy = [0,0,1,-1]
        L = []
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 2:
                    L.append([i,j])
        minute = 0
        while (L):
            newL = []
            for i in L:
                x0 = i[0]
                y0 = i[1]
                for k in range(4):
                    x = x0+dx[k]
                    y = y0+dy[k]

                    if 0 <= x < len(grid) and 0 <= y < len(grid[0]) and grid[x][y] == 1:
                        grid[x][y] = 2 # 腐烂
                        newL.append([x,y])
            if not newL: #没有新腐烂的橘子了
                break
            L = newL[:]
            minute += 1
        for row in grid:
            for i in row:
                if i == 1:
                    return -1 # 这都没烂完啊？
        return minute
```
