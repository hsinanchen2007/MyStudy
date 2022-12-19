### 解题思路
从下往上找，先把最底层元素赋值给dp，然后依次向上层寻找最小值
空间复杂度O(n)

### 代码

```python
class Solution(object):
    def minimumTotal(self, triangle):
        r = len(triangle)
        dp = triangle[-1]
        for i in range(r-2,-1,-1):
            for j in range(i+1):
                dp[j] = min(dp[j] + triangle[i][j],dp[j+1] + triangle[i][j])
        return dp[0]
```