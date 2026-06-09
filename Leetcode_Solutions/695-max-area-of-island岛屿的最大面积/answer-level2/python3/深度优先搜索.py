### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
                #深度优先搜索
       
        def dfs(grid_l,visited_l,i,j):
           
            if grid_l[i][j]==0:
                return
            if visited_l[i][j]==0 and grid_l[i][j]==1:
                visited_l[i][j]=1               
                num[0]+=1
                
                if(i-1>=0):
                    dfs(grid_l,visited_l,i-1,j)
                if(i+1< m):                    
                    dfs(grid_l,visited_l,i+1,j)
                if(j-1>=0):                    
                    dfs(grid_l,visited_l,i,j-1)
                if(j+1< n):                    
                    dfs(grid_l,visited_l,i,j+1)                
        visited=[]
        m=len(grid)
        n=len(grid[0])       
        
        for i in range(m):
            temp=[]
            for j in range(n):          
                temp.append(0)
            visited.append(temp)
        if n==0 :return 0              
        s_max=0
        num=[0]
        for i in range(m):            
            for j in range(n):                
                if visited[i][j]==0:
                    dfs(grid,visited,i,j)                    
                    s_max=max(s_max,num[0])
                    num[0]=0
        return s_max
```