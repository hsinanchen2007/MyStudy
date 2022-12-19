从前往后遍历，一次累加即可， 不用重复遍历
```
class Solution:
    def maxValue(self, grid) -> int:
        # memo = {}
        # #dp 方式处理 存在重复遍历的情况
        # def search(m,n):
        #     if (m,n) in memo:
        #         return memo[(m,n)]
        #     if m==0 and n==0: return grid[0][0]
        #     if m==0:
        #         memo[(m,n)] = grid[m][n]+search(m,n-1)
        #         return memo[(m,n)]
        #     if n==0: 
        #         memo[(m,n)] = grid[m][n]+search(m-1,n)
        #         return memo[(m,n)]
        #     memo[(m,n)] = grid[m][n]+max(search(m-1,n),search(m,n-1))
        #     return memo[(m,n)]
        # return search(len(grid)-1,len(grid[0])-1)
        m,n = len(grid),len(grid[0])
        for i in range(1,m):
            grid[i][0] += grid[i-1][0]
        for j in range(1,n):
            grid[0][j] += grid[0][j-1]
        for i in range(1,m):
            for j in range(1,n):
                grid[i][j] = grid[i][j] + max(grid[i-1][j], grid[i][j-1])
        return grid[-1][-1]

```
