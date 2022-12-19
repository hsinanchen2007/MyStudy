![image.png](https://pic.leetcode-cn.com/c29001e8181c0472d9190973d1277d60d0fab263e32dfae9270aa29ebc2a02d6-image.png)


```

'''
动态规划求左上(0, 0) 到 右下(i, j)的子矩阵的数值和
再利用一次动态规划思想利用上述数值和快速求每个宽度为2k + 1的正方形子矩阵和
'''

from typing import List
class Solution:
    def matrixBlockSum(self, mat: List[List[int]], K: int) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        dp = [[0 for _ in range(n)] for _ in range(m)]

        dp[0][0] = mat[0][0]
        for j in range(1, n):
            dp[0][j] = dp[0][j - 1] + mat[0][j]
        for i in range(1, m):
            dp[i][0] = dp[i - 1][0] + mat[i][0]

        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i][j]

        ans = [[0 for _ in range(n)] for _ in range(m)]

        # 枚举每一个正方形的中心
        for i in range(m):
            for j in range(n):
                ii1, jj1, ii2, jj2 = max(0, i - K), max(0, j - K), min(m-1, i + K), min(n-1, j + K)

                if ii1 == 0 and jj1 == 0:
                    ans[i][j] = dp[ii2][jj2]
                elif ii1 == 0:
                    ans[i][j] = dp[ii2][jj2] - dp[ii2][jj1-1]
                elif jj1 == 0:
                    ans[i][j] = dp[ii2][jj2] - dp[ii1-1][jj2]
                else:
                    ans[i][j] = dp[ii2][jj2] - dp[ii2][jj1-1] - dp[ii1-1][jj2] + dp[ii1-1][jj1-1]
        return ans
```
