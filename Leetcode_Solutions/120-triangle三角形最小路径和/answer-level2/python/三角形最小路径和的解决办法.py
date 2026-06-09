### 解题思路
此处撰写解题思路
1、正向解法： f[i][j] = min(f[i-1][j],f[i-1][j]) + cur_value ,需要判断异常条件，因为三角形是不对等的。
2、逆向解法：最后一行一定是最全的一行，因此该方法不需要判断异常条件。dp[i] = min(dp[i],dp[i+1]) + cur_value。
  即 f[i][j] = min(f[i+1][j],f[i+1][j+1]) + cur_value,然后将多维数据转换成一维数据。

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
        dp = triangle[-1]
        n = len(triangle)
        for i in range(n-2,-1,-1):
            for j,data in enumerate(triangle[i]):
                dp[j] = min(dp[j],dp[j + 1]) + data
        return dp[0]
```