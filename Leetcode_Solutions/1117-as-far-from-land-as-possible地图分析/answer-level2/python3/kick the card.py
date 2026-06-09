### 解题思路

punch in the card. 
Again, I will give you the code. 

### 代码

```python3
def finish(grid):
    for i in grid:
        for j in i:
            if j==0:
                return False
    return True

def notStart(grid):
    for i in grid:
        for j in i:
            if j==1:
                return False
    return True

class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        if len(grid)==0:
            return 0
        if notStart(grid) or finish(grid):
            return -1
        self.grid=grid
        self.next=[[0 for i in range(len(grid[0]))] for j in range(len(grid))]
        time=0
        while(self.round()):
            time+=1
        return time

    def round(self):
        change=False
        for i in range(len(self.grid)):
            for j in range(len(self.grid[0])):
                if self.grid[i][j]:
                    self.next[i][j]=1
                elif i>0 and self.grid[i-1][j]:
                    self.next[i][j]=1
                    change=True
                elif j>0 and self.grid[i][j-1]:
                    self.next[i][j]=1
                    change=True
                elif j<len(self.grid[i])-1 and self.grid[i][j+1]:
                    self.next[i][j]=1
                    change=True
                elif i<len(self.grid)-1 and self.grid[i+1][j]:
                    self.next[i][j]=1
                    change=True
        self.grid,self.next=self.next,self.grid
        return change
```