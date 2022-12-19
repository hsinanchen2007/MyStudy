```
class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        这里和前面不一样的是需要存储size，所以给递归函数需要一个返回值，（不要用全局变量）
        """
        max_area=0
        res=0
        
        def infect(grid,i,j):

            ''' 这个是DFS函数，一般不用修改，功能就是遍历和(i,j)相连的所有格子'''

            #遇到边界，或者不是1的地方就返回
            if(i<0 or i>=len(grid) or j<0 
               or j>=len(grid[0]) or grid[i][j]!=1
               ):
                return 0
            grid[i][j]=2
            return 1+infect(grid,i,j+1)+infect(grid,i,j-1)+infect(grid,i+1,j)+infect(grid,i-1,j)
        
#        也可以像下面这样分开写
#            res=1
#            往四周感染
#            res+=infect(grid,i,j+1)
#            res+=infect(grid,i,j-1)
#            res+=infect(grid,i+1,j)
#            res+=infect(grid,i-1,j)
#            return res
            
            
        #主函数
        for i in range(0,len(grid)):
            for j in range(0,len(grid[0])):
                self.size=0
                if(grid[i][j]==1):
                    res=infect(grid,i,j)#开始感染
                    max_area=max(res,max_area)
        return max_area
```
