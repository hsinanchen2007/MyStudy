![image.png](https://pic.leetcode-cn.com/9bb98100db2ddb6c1fca9887c957fc231f207450faf94d8bddf2d690fb2c70f9-image.png)


```
'''
dp(i, j)表示右下角为(i, j) 左上角为(0, 0)的矩形区域和，二维动态规划计算
然后迭代正方形的左上角和边长，求最大边长
'''


from typing import List
class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        m, n = len(mat), len(mat[0])
        dp = [[0 for _ in range(n)] for _ in range(m)]

        dp[0][0] = mat[0][0]
        for j in range(1, n):
            dp[0][j] = dp[0][j-1] + mat[0][j]
        for i in range(1, m):
            dp[i][0] = dp[i-1][0] + mat[i][0]

        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mat[i][j]

        # 枚举正方形左上角和边长
        ans = 0
        for i in range(m):
            for j in range(n):
                max_edge_len = min(m - i, n - j)

                # 二分找最佳边长
                l, r = 1, max_edge_len
                while l <= r:
                    edge_len = l + (r - l) // 2

                    ii, jj = i + edge_len - 1, j + edge_len - 1

                    if i == 0 and j == 0:
                        val = dp[ii][jj]
                    elif i == 0:
                        val = dp[ii][jj] - dp[ii][j-1]
                    elif j == 0:
                        val = dp[ii][jj] - dp[i-1][jj]
                    else:
                        val = dp[ii][jj] - dp[ii][j-1] - dp[i-1][jj] + dp[i-1][j-1]

                    if val <= threshold:
                        ans = max(ans, edge_len)
                        l = edge_len + 1
                    else:
                        r = edge_len - 1

        return ans
```
