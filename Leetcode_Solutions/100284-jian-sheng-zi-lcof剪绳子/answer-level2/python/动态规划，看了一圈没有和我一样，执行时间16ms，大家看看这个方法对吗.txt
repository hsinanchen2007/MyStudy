### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def cuttingRope(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp=[1 for _ in range(n+1)]
        for i in range(3,n+1):
            core=0
            for j in range(2,i):
                core=max(core,dp[j]*(i-j),j*(i-j))
            dp[i]=core
        return dp[n]
```