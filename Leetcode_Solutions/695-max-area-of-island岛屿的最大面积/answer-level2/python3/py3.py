```
class Solution:
    def maxAreaOfIsland(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        row=len(grid)
        col=len(grid[0])
        mark=[[0]*col for i in range(row)] 
        area=0

        def land(i,j,mark,num):
            #print(i,j)
            mark[i][j]=1
            num+=1
            der_list=[[0,1],[1,0],[0,-1],[-1,0]]
            for der in der_list:
                m=i+der[0]
                n=j+der[1]
                #print(i,j)
                if 0<=m<row and 0<=n<col and grid[m][n]==1 and mark[m][n]==0:
                    num=land(m,n,mark,num)
            #print(num)
            return num

        for i in range(row):
            for j in range(col):
                if grid[i][j]==1 and mark[i][j]==0:                  
                    temp=land(i,j,mark,0)
                    if temp>area:
                        area=temp
        
        return area
```
