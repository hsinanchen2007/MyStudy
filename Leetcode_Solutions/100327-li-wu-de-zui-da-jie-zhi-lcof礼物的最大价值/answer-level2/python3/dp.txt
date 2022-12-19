```
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        # def find(i,j, count):
        #     if i >= len(grid) or j >= len(grid[0]): return count
        #     count +=grid[i][j]
        #     return max( find(i+1,j, count), find(i, j+1, count))
        # if len( grid) == 0: return 0
        # if len(grid[0]) ==0: return 0
        # return find(0,0,0)
        if len( grid) == 0: return 0
        if len(grid[0]) ==0: return 0
        dp = [[0] * (len(grid[0])+1) for _ in range(len(grid)+1)]
        for i in range(len(grid)-1, -1, -1):
            for j in range(len(grid[0])-1, -1, -1):
                dp[i][j] = grid[i][j] + max(dp[i][j+1], dp[i+1][j])
        return dp[0][0]
```
