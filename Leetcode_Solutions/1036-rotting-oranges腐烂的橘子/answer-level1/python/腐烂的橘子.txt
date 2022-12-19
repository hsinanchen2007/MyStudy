
### 代码

```python
class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m,n = len(grid),len(grid[0])
        rot,flag = [],0
        for i in range(m):
            for j in range(n):
                if grid[i][j]==2:
                    rot.append([i,j]) #腐烂的橘子入队
                if grid[i][j]==1:
                    flag = 1
        if flag == 0: #特殊情况判断
            return 0
        if not rot: #特殊情况判断
            return -1
        minute = 0
        while rot:
            l = len(rot)
            flag = 0 #是否感染的标记
            for i in range(l): #开始感染
                org = rot[0]
                del rot[0]
                i,j = org[0],org[1]
                if i!=0 and grid[i-1][j]==1: #up方向
                    grid[i-1][j] = 2
                    rot.append([i-1,j])
                    flag = 1
                if i!=m-1 and grid[i+1][j]==1: #down方向
                    grid[i+1][j] = 2
                    rot.append([i+1,j])
                    flag = 1
                if j!=0 and grid[i][j-1]==1: #left方向
                    grid[i][j-1] = 2
                    rot.append([i,j-1])
                    flag = 1
                if j!=n-1 and grid[i][j+1]==1: #right方向
                    grid[i][j+1] = 2
                    rot.append([i,j+1])
                    flag = 1
            if flag == 1: #有感染动作发生
                minute += 1  #minute加一 
        flag = 0
        for i in range(m): #判断是否还有未被感染的橘子
            for j in range(n):
                if grid[i][j]==1:
                    flag = 1   
        if flag==1:
            return -1 
        return minute




               



```