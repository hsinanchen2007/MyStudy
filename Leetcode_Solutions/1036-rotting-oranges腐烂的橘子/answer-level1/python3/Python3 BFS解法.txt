
分别将腐烂的橘子和新鲜的橘子保存在两个集合中。进行BFS搜索，如果有腐烂的，时间+1并且从新鲜的橘子集合中剔除腐烂的橘子。直到橘子全部腐烂是结束循环返回minute，否则无法全部腐烂返回-1


```python
class Solution:
    def orangesRotting(self,grid):
        """
        :param grid: List[List[int]]
        :return: int
        """
        
        m=len(grid)
        n=len(grid[0])
        
        rotten={(i,j) for i in range(m) for j in range(n) if grid[i][j]==2}
        fresh={(i,j) for i in range(m) for j in range(n) if grid[i][j]==1}
        
        minute=0
        while fresh:
            if not rotten:
                return -1
            rotten={(i+dir_i,j+dir_j) for i,j in rotten for dir_i,dir_j in [(0,1),(0,-1),(-1,0),(1,0)] if (i+dir_i,j+dir_j) in fresh}
            
            fresh-=rotten
            
            minute+=1
            
        return minute
            
    
```
