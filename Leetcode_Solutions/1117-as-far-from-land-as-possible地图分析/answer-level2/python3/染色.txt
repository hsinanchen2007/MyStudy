对每一个陆地，向周围四个方向进行染色（有点像BFS）。每次最多染4个区域，逐次染色颜色加深。
每次进行染色时将搜索到的0，或者大于该次染色深度的，置为当前染色值。
如果发现全部海洋都被染色了，返回最深的颜色。

```
class Solution:
    def maxDistance(self, grid) -> int:
        ans = 0
        stage = 1 #每陆地开始，第一个染色时stage+1，区分出陆地
        n = len(grid)
        for i in grid:
            ans += sum(i)
        if ans == 0 or ans == n*n:
            return -1
        # 判断是不是全是陆地或者海洋，是的话返回-1
        while(1):
            for i in range(n):
                for j in range(n):
                    #从每一批颜色出发，颜色逐渐扩散
                    if grid[i][j] == stage:
                        for move_i,move_j in [1,0],[-1,0],[0,1],[0,-1]:
                            if i+move_i < 0 or i+move_i > n - 1 or j+move_j < 0 or j+move_j > n - 1:
                                continue
                            if grid[i+move_i][j+move_j] > stage + 1 or grid[i+move_i][j+move_j] == 0:
                                grid[i+move_i][j+move_j] = stage + 1
            for i in grid:
                if 0 in i:
                    break              
            else:
                break
            stage += 1
                                
        return stage     
```
