运行时间：
![image.png](https://pic.leetcode-cn.com/72b83098e8abaf6e3773dc061b43440f592949e5da5f4b255f6cc3294c41d09e-image.png)
利用dp[i]=dp[i-1]+dp[i-2]
 **注意取模不要使用科学计数法**
```

class Solution(object):
    def fib(self, n):
        """
        :type n: int
        :rtype: int
        """

        dp =[1 for _ in range(n+1)]
        dp[0]=0
        if n<3:
            return dp[n]
        for i in range(3,n+1):
            dp[i]=dp[i-1]+dp[i-2]
        return dp[n]%(1000000007)
```
