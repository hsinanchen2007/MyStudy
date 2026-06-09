### 解题思路
DFS


### 代码

```python
class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if not grid:
            return 0
        n = len(grid)-1 #行数(0-n)
        m = len(grid[0])-1 #列数(0-m)

        def zero(i,j):
            if grid[i][j] == '0':
                return 
            grid[i][j] = '0'
            if i > 0:
                zero(i-1, j)
            if j > 0:
                zero(i, j-1)
            if i < n:
                zero(i+1, j)
            if j < m:
                zero(i, j+1)
            
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '0':
                    continue
                else:
                    count += 1
                    zero(i,j)
                    #print(grid)

        return count

```