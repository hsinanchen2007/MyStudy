### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def fib(self, N: int) -> int:
        '''
        if N<2:
            return N
        return self.fib(N-1)+self.fib(N-2)
        '''
        dp={}
        dp[0],dp[1],i = 0,1,2
        while i<=N:
            dp[i] = dp[i-1]+dp[i-2]
            i+=1
        return dp[N]
```