![image.png](https://pic.leetcode-cn.com/79ed3894d7bb3b6a20c018c7f20a1cff88d7c3fa51318faf1a647878d0efa9b4-image.png)


```
'''
floyd算法先求任意两点之间的最短路径长度，然后针对各个城市为起点筛选小于等于distanceThreshold的合法路径，
选取出合法路径最少的城市
'''

from typing import List
class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        dp = [[0x7fffffff for _ in range(n)] for _ in range(n)]
        for node1, node2, dis in edges:
            dp[node1][node2] = dis
            dp[node2][node1] = dis
        for i in range(n):
            dp[i][i] = 0

        for k in range(0, n):   # 枚举中介点
            for i in range(0, n):
                for j in range(0, n):
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])

        min_cnt = 0x7fffffff
        ans = -1
        for i in range(n):
            cnt = 0
            for j in range(n):
                if dp[i][j] <= distanceThreshold:
                    cnt += 1

            if cnt <= min_cnt:
                ans = i
                min_cnt = cnt

        return ans
```
