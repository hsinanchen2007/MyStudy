### 解题思路
没什么好说的，直接看代码吧，自底向上逐个计算就好了

### 代码

```python3
class Solution:
    def tribonacci(self, n: int) -> int:
        dp=[0]* max(3,n+1)
        dp[1],dp[2]=1,1
        if n<3:
            return dp[n]
        for i in range(3,n+1):
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3]
        return dp[n]
      
```