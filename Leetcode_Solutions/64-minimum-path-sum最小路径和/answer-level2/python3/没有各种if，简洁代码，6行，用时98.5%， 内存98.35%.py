```
class Solution:
    def uniquePathsWithObstacles(self, grid: List[List[int]]) -> int:
        dp = [float('inf') for _ in range(len(grid[0])+1)]
        dp[0] = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                    dp[j] = min(dp[j-1], dp[j]) + grid[i][j]
            # print(dp)
        return dp[-2]
```
利用dp多出来的最后一个维度，设成inf，没有if判断，最后return dp[-2]
