### 解题思路
对动态规划比较熟悉，采用标准的动态规划解题并进行优化。空间复杂度O(n)
注意一下更新d[0] d[n]的时机，循环的顺序，其他都比较简单，
供采用动态规划的参考。
### 代码

```python3
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if triangle == None:
            return 0
        n = len(triangle)
        if n == 1:
            return triangle[0][0]
        if n == 2:
            return min(triangle[1][0], triangle[1][1]) + triangle[0][0] 
        dp = [None for i in range(n)]
        dp[0] = triangle[0][0] + triangle[1][0]
        dp[1] = triangle[0][0] + triangle[1][1]
        for i in range(2, n):
            dp[i] = dp[i-1] + triangle[i][i]
            for j in range(i-1, 0, -1):  # 从后向前遍历，不然会覆盖掉后的值导致计算出错
                # 递归方程,
                dp[j] = min(dp[j-1], dp[j]) + triangle[i][j]
            dp[0] = dp[0] + triangle[i][0]  #第一个更新
        return min(dp)
```