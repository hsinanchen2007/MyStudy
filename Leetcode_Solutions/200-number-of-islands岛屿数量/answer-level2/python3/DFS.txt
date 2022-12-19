解题思路，DFS即可，遍历所有岛屿并用一个visited标注是否访问。有访问返回1即可。
```
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        num = 0
        if not grid:
            return 0
        n,m = len(grid),len(grid[0])
        visited = [[0]*m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                num += self.dfs(grid,visited,i,j)
        return num
    
    
    def dfs(self,grid,visited,i,j):
        
        if(i<0 or j<0 or i==len(grid) or j==len(grid[0]) or visited[i][j]):
            return 0
        
        if(grid[i][j] == '1'):
            visited[i][j] = 1
            for (pos1,pos2) in ((-1,0),(1,0),(0,1),(0,-1)):
                self.dfs(grid,visited,pos1+i,pos2+j)
           
            return 1
        return 0
            
```