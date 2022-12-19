### 解题思路
core：`dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]) + triangle[i][j] `
dp：从底层走到当前节点的最短路径
从底向上计算出当前节点能走的最短路径。因为只需要计算i层的dp只需要读取i-1层dp数组，所以dp数组可以变成一维。最后计算完成的dp[0]就是顶端的最小距离值

### 代码

```python
class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        if not triangle:
            return 0

        n = len(triangle)
        #basecase
        dp = [0] * len(triangle[-1])
        for x in range(len(triangle[-1])):
            dp[x] = triangle[-1][x]

        for i in range(n-2, -1, -1):
            for j in range(len(triangle[i])):
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j]
        return dp[0]

```