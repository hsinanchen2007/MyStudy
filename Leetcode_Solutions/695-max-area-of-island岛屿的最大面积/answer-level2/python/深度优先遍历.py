### 解题思路
此处撰写解题思路


### 代码

```python
def DFS(grid,mark,x,y):
    
    mark[x][y]=1
    dx=[-1,1,0,0]
    dy=[0,0,-1,1]
    
    ans=1

    for i in range(4):
        newx=x+dx[i]
        newy=y+dy[i]
        if (newx<0 or newx>=len(grid)) or (newy<0 or newy>=len(grid[newx])):
            continue
        
        if grid[newx][newy]==1 and mark[newx][newy]==0:
            ans=ans+DFS(grid,mark,newx,newy)
    
    return ans 
            
            



class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        mark=[[0 for j in range(len(grid[i]))] for i in range(len(grid))]
    
        lis=[]
        lis.append(0)
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j]==1 and mark[i][j]==0:
                    ans=DFS(grid,mark,i,j)
                    lis.append(ans)

        return max(lis)
                    
                    
                
```