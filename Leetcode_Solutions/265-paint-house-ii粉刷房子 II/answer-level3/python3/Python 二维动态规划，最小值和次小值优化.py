
![image.png](https://pic.leetcode-cn.com/df7b462893dc8c5c0262f1454227bed0d04e6630ba69222d43eb8c8d682f0a68-image.png)

```

'''
二维动态规划
dp[i][j] 前i个房子，最后一个房子刷颜色j的最小花费
每一行dp计算完之后维护最小值和次小值，给下一轮dp使用
'''

from typing import List
class Solution:
    def minCostII(self, costs: List[List[int]]) -> int:
        if len(costs) == 0:
            return 0

        n, k = len(costs), len(costs[0])
        dp = [[0x7fffffff for _ in range(k)] for _ in range(n)]

        for i in range(n):
            for j in range(k):
                if i == 0:
                    dp[0][j] = costs[0][j]

                else:
                    color, cost = min_val[0]
                    if color == j:
                        color, cost = min_val[1]
                    dp[i][j] = cost + costs[i][j]

            # 求最小值和次小值
            min_val = [(0, dp[i][0]), None]  # (color, cost)
            for color in range(1, k):
                if dp[i][color] < min_val[0][1]:
                    min_val[1] = min_val[0]
                    min_val[0] = (color, dp[i][color])
                elif min_val[1] is None or dp[i][color] < min_val[1][1]:
                    min_val[1] = (color, dp[i][color])

        return min(dp[n-1])
```
