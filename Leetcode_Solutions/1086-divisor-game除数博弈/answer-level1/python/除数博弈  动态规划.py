### 解题思路

### 代码

```python
class Solution(object):
    def divisorGame(self, N):
        dp = [False]*(N+1)
        if N == 2:
            dp[1] = False
            dp[2] = True
        if N > 2:
            dp[1] = False
            dp[2] = True
            for i in range(3,N+1):
                for j in range(1,i):
                    if dp[i-j] == False and i % j == 0:#Alice能否找到一个j,使得dp[i-j]=False(下一次Bob先行会输)
                        dp[i] = True
                        break        
        return dp[N]
```