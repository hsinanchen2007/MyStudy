### 解题思路
此处撰写解题思路

直接当dp来解
找规律比较恶心
        """
        # 假设最坏情况
        # 那么n = 1+1+1+...1    num = n
        # 那么我们可以设计dp来找找规律
        '''
        dp = []
        if n == 0:
            return len(dp)
        if n == 1:
            dp[0] = 1
        if n == 2:
            dp[1] = 2 = dp[0] + dp[0] 
        if n == 3:
            dp[2] = 3 = dp[1] + dp[0] = 2 + 1
        if n == 4:
            dp[3] = 1 = min(4, 1+1+1+1 ) = min(dp[int(sqrt(12))**2]+dp[3],...) = min(dp[9]+dp[3], dp[8]+dp[4], dp[7]+dp[5]...)
        if n == 12:
            dp[12] = 3 = min(11 +1, 10+2, 9+3, 8 + 4, ...4... ) = dp[8]+dp[4] = 2+1 = 3
        那么转移方程就出来了
        '''

### 代码

```python
class Solution(object):
    def numSquares(self, n):

        dp = [0 for _ in range(n+1)]
        if n == 0:
            return 0
        for i in range(n+1):
            if i == 0:
                dp[i] = 0
            if i == 1:
                dp[i] = 1
            if i > 1:
                ideal_factor =  (int(i**0.5))**2
                if ideal_factor == i:
                    dp[i] = 1
                else:
                    factor = int(i**0.5)
                    min_step = i
                    for j in range(1,factor+1):
                        min_step = min(min_step, dp[j**2]+dp[i-j**2])
                    dp[i] = min_step
        
        return dp[-1]
                        
```