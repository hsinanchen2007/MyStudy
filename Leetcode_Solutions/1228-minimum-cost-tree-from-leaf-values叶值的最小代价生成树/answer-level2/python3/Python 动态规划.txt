

```
'''
动态规划
最后一定是形成序列arr, 只需要看两棵子树是这个序列里面哪两个子序列形成的
其实就是找最好的分裂点，让左右子树合起来后，形成的非叶子节点数值和最小
dp(i, j)表示下标从i到j的序列代表的子树的非叶子节点的最小和
'''

from typing import List
class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        n = len(arr)
        dp = [[0 for _ in range(n)] for _ in range(n)]

        for i in range(n-1, -1, -1):
            for j in range(i+1, n):
                dp[i][j] = 0x7fffffff
                for k in range(i, j):
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + max(arr[i:k+1]) * max(arr[k+1:j+1]))
        return dp[0][n-1]

```
