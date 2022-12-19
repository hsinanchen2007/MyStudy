![image.png](https://pic.leetcode-cn.com/20ecac406e91994017242314832946234869ba48ee3ce3ccbf56ab6611536354-image.png)
### **关键点**：①dp[i] = dp[i-1]+dp[i-2]+dp[i-3]
        ②*处理base条件*
```
class Solution(object):
    def waysToStep(self, n):
        if n<3:
            return n
        if n>=3:
            dp = [0]*n
            dp[0] = 1
            dp[1] = 2
            dp[2] = 4
        for i in range(3,n):
            dp[i] = (dp[i-1]+dp[i-2]+dp[i-3])%1000000007
        return dp[n-1]
```
