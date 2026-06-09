遍历网格时，要注意区分刚被传染坏的橘子和已经坏掉的橘子。
方法感觉挺笨的。
```
class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        time=0
        status=1
        while status:
            status=0
            grid,status=self.rotten(grid)
            "遍历grid"
            "如果有新腐烂的橘子,status=1"
            if not status:
                for i in range(len(grid)):
                    for j in range(len(grid[0])):
                        if grid[i][j]==1:
                            return -1
                return time
            time=time+1
        return time  
    def rotten(self,grid):
        rows,cols=len(grid),len(grid[0])
        status=0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j]==2:
                    if j-1>= 0 and grid[i][j-1]==1:
                        grid[i][j-1]=3
                        status=1
                    if i-1>=0 and grid[i-1][j]==1:
                        grid[i-1][j]=3
                        status=1
                    if j+1<cols and grid[i][j+1]==1:
                        grid[i][j+1]=3
                        status=1
                    if i+1<rows and grid[i+1][j]==1:
                        grid[i+1][j]=3
                        status=1
        for i in range(rows):
            for j in range(cols):
                if grid[i][j]==3:
                    grid[i][j]=2
        return grid,status
```

