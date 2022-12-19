### 解题思路
很常见的动态规划的问题。
对于将空间复杂度从O(n*m)优化成O(n),可以看到，在循环过程中，计算dp[i][j]只需要用到
左边的元素和上面的元素，即计算第i行，要用到第i-1行的元素，其他行的都不需要，所以就只
需要保存一行元素的值，然后不断更新就可以了。
### 代码

```python3
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp =[[1 for j in range(n)] for i in range(m)]
        # 上面相当于已经设置过初始值了，直接开始循环地推
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[m-1][n-1]


```

```
# 优化
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp =[1 for j in range(n)]
        # 上面相当于第一行的初始值
        for i in range(1,m):
            dp[0] = 1
            for j in range(1,n):
                dp[j] = dp[j] + dp[j-1]
        return dp[-1]
```