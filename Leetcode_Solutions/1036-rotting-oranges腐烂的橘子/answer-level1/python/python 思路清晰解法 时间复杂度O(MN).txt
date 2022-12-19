### 解题思路
1. 储存臭橘子的位置和初始时间
2. n时刻的臭橘子开始向n+1时刻开始蔓延    (0<=n)
3. 全部腐烂传播结束后，检查新鲜橘子的存在
4. 根据情况返回  t  or  -1   or   0

### 代码

```py
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        flag = False                         #记录全盘中有没有臭橘子
        row = len(grid)
        column = len(grid[0])
        ans = []
        #记录全盘中腐烂橘子的位置和时间，开始时间记为0  （x,y,t）
        for i in range(row):
            for j in range(column):
                if grid[i][j] == 2:          
                    flag = True
                    ans.append((i,j,0)) 
                    
        while ans:
            #首先对时间为0的臭橘子开始第一分钟的传播，第二分钟……
            i,j,t = ans.pop(0)             
            for x,y in [(i-1,j),(i+1,j),(i,j+1),(i,j-1)]:              #判断四个方向
                if 0<=x<row and 0<=y<column and grid[x][y] == 1:
                    grid[x][y] = 2                                     #将新鲜橘子腐烂，记录腐烂时间
                    ans.append((x,y,t+1))
        #检查还有没有新鲜橘子了
        for i in range(row):                                           
            for j in range(column):
                if grid[i][j] == 1:
                    return -1
        #没有新鲜橘子，没有过臭橘子返回0
        if flag: return t                                              
        else:return 0
```