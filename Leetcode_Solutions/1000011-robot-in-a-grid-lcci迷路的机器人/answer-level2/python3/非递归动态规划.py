```python
from collections import defaultdict
class Solution:
    def pathWithObstacles(self,
                          obstacleGrid: List[List[int]]) -> List[List[int]]:
        # 简单的dp, dp存路径中的上一个节点, 不能存所有可能的路径, 会超时
        # 只需要其中一个路径即可
        if not obstacleGrid or obstacleGrid[0][0] == 1:
            return []
        dp = defaultdict(list)
        dp[0, 0] = [0, 0]
        rows, cols = len(obstacleGrid), len(obstacleGrid[0])
        for r in range(1, rows):
            if obstacleGrid[r][0] == 1:
                break
            dp[r, 0] = [r - 1, 0]
        for c in range(1, cols):
            if obstacleGrid[0][c] == 1:
                break
            dp[0, c] = [0, c - 1]
        for r in range(1, rows):
            for c in range(1, cols):
                if obstacleGrid[r][c] == 0:
                    if dp[r - 1, c]:
                        dp[r, c] = [r - 1, c]
                    if dp[r, c - 1]:
                        dp[r, c] = [r, c - 1]
        if not dp[rows - 1, cols - 1]:
            return []
        cur = [rows - 1, cols - 1]
        res = [[rows - 1, cols - 1]]
        while cur != [0, 0]:
            r, c = cur
            cur = dp[r, c]
            res.append(cur)
        return res[::-1]
```
