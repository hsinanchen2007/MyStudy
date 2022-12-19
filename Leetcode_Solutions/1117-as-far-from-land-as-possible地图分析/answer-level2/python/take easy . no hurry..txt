### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        for i, row in enumerate(grid):
            for j, value in enumerate(row):
                if value == 0:
                    grid[i][j] = float('inf')
                else:
                    grid[i][j] = 0
        ans = 0
        n = len(grid)    
        for i, row in enumerate(grid):
            for j, value in enumerate(row):
                if value != 0:
                    if i-1 >= 0: grid[i][j] = min(grid[i][j], grid[i-1][j]+1)
                    if j-1 >= 0: grid[i][j] = min(grid[i][j], grid[i][j-1]+1)
        #for i, row in enumerate(reversed(grid)):
            #for j, value in enumerate(reversed(row)):
                 #if i-1 >= 0: grid[i][j] = min(grid[i][j], grid[i-1][j]+1)
                    #if j-1 >= 0: grid[i][j] = min(grid[i][j], grid[i][j-1]+1)
        #这里错在位置是reversed grid， 但是修改的值还是grid[i][j]
        for i in reversed(range(n)):
            for j in reversed(range(n)):
                if grid[i][j] != 0:
                    if i+1 < n: grid[i][j] = min(grid[i][j], grid[i+1][j]+1)
                    if j+1 < n: grid[i][j] = min(grid[i][j], grid[i][j+1]+1)
                ans = max(grid[i][j], ans)
        if ans == float('inf') or ans == 0:
            return -1
        return ans
```