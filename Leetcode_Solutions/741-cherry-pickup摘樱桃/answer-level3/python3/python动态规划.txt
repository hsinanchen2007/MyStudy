### 解题思路
从花花酱得来思路，把题目转换成两个人从右下角终点同时往左上起点走，坐标是(x1,y1)和(x2,y2)，由于是同时走，所以可以降维，y2=x1+y1-x2
初始值设为最小值，来标记是否走过这个路线，否则直接返回这个记忆体
处理好边界即可

### 代码

```python3
class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        n = len(grid)
        dp = [[[float('-inf')] * n for _ in range(n)] for _ in range(n)]
        def helper(x1, y1, x2):
            y2 = x1 + y1 - x2
            if x1 < 0 or x2 < 0 or y1 < 0 or y2 < 0:
                return -1
            if grid[x1][y1] < 0 or grid[x2][y2] < 0:
                return -1
            if x1 == 0 and y1 == 0:
                return grid[x1][y1]
            if dp[x1][y1][x2] != float('-inf'):
                return dp[x1][y1][x2]
            
            res = max(
                        max(helper(x1 - 1, y1, x2 - 1), helper(x1, y1 - 1, x2)),
                        max(helper(x1, y1 - 1, x2 - 1), helper(x1 - 1, y1, x2))   
                )
            if res < 0:
                dp[x1][y1][x2] = -1
            else:
                res += grid[x1][y1]
                if x1 != x2:
                    res += grid[x2][y2]
                dp[x1][y1][x2] = res
            return dp[x1][y1][x2]

        return max(0, helper(n - 1, n - 1, n - 1))
```