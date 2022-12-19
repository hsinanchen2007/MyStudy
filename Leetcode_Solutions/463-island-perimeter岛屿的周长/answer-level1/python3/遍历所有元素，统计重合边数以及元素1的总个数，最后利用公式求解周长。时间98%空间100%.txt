```
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        r_sub = 0 #当前元素右侧元素为1时的累计重叠次数
        b_sub = 0 #当前元素下侧元素为1时的累计重叠次数
        total_1 = 0  #统计元素1的总次数
        w = len(grid[0]) #宽
        h = len(grid)     #高
        for i in range(h):
            for j in range(w):
                if grid[i][j] == 1:
                    total_1 += 1    #若当前元素为1，累加一次
                    if j+1 < w and grid[i][j+1] == 1:    #判断当前元素1右侧是否也为元素1，若为1则右方重合边数累加一次
                        r_sub += 1
                    if i+1 < h and grid[i+1][j] == 1:    #判断当前元素1下侧是否也为元素1，若为1则下方重合边数累加一次
                        b_sub += 1                       
            
        return 4*total_1 - 2*(r_sub + b_sub)  #周长计算公式（4*元素1的个数-2*重合的边数）
        
```
