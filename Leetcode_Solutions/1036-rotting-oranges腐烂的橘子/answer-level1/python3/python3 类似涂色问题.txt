执行用时 :
68 ms, 在所有 Python3 提交中击败了36.83%的用户
内存消耗 :13.4 MB, 在所有 Python3 提交中击败了17.24%的用户
```
class Solution:
    def __init__(self):
        self.directions=[(0,1),(0,-1),(1,0),(-1,0)]
        self.minute=0
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m=len(grid)
        if len(grid)==0:
            return -1
        n=len(grid[0])
        
        def getRotten(i,j):#腐烂过程
            # print(grid)
            # print(i,j)
            for direction in self.directions:
                    new_i=i+direction[0]
                    new_j=j+direction[1]
                    if 0<=new_i<m and 0<=new_j<n :
                        if grid[new_i][new_j]==1:
                            grid[new_i][new_j]=grid[i][j]+1
                            # self.minute=max(self.minute,grid[new_i][new_j]-2)
                            getRotten(new_i,new_j)
                        if grid[new_i][new_j]>grid[i][j]+1:
                            grid[new_i][new_j]=grid[i][j]+1
                            # self.minute=min(self.minute,grid[new_i][new_j]-2)
                            getRotten(new_i,new_j)


                        
        for i in range(m):
            for j in range(n):   
                if grid[i][j]==2:
                    getRotten(i,j)
                
        # print(grid)
        for i in range(m):
            for j in range(n):    
                if grid[i][j]==1:
                        return -1
                self.minute=max(self.minute,grid[i][j]-2)
        return self.minute
```
