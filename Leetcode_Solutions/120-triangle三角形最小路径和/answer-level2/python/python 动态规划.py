### 解题思路
只需使用一维的数组存放DP结果，从上到下，从右往左遍历

### 代码

```python3
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:

        n = len(triangle)
        if n == 1:
            return triangle[0][0]
        dp = [0] * n
        dp[0] = triangle[0][0]

        for i in range(1, n):
            dp[i] = dp[i - 1] + triangle[i][i]

            for j in range(i - 1, 0, -1):
                dp[j] = min(dp[j], dp[j-1]) + triangle[i][j]

            dp[0] = dp[0] + triangle[i][0]
        return min(dp)



```