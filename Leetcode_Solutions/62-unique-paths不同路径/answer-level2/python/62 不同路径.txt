### 解题思路
动态规划
根据题目要求只能向下或者向右移动,所以到达节点的路径应该是这两个方向的总和,可以写出状态转移方程为:
dp[i][j] = dp[i-1][j] + dp[i][j-1]
空间复杂度O(m*n)


### 代码

```python
class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """

        dp = [[1]*n for i in range(m)]
        print dp
   
        for i in range(m):
            for j in range(n):
                if i == 0 or j == 0:
                    continue
                dp[i][j] = dp[i-1][j] + dp[i][j-1]

        return dp[-1][-1]
```