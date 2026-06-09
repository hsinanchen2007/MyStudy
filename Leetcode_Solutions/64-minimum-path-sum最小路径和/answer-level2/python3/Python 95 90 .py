![image.png](https://pic.leetcode-cn.com/076409a371439b8e4ed0690420e3021ba348b6a346948d8bd425f7f1e85d13ac-image.png)

```
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:
            return 0
        t = sum(grid[0])
        dp = [0] * (len(grid[0])+1)
        for i in range(len(grid[0])):
            dp[i+1] = dp[i] + grid[0][i]
        dp[0] = float("inf")
        for i in range(1,len(grid)):
            for j in range(len(grid[0])):
                dp[j+1] = grid[i][j]+min(dp[j],dp[j+1])
                # print(dp)
        return dp[-1]
```
