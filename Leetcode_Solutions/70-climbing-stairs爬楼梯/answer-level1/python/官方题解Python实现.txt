### 解题思路
首先想到的是利用**递归**（暴力法）求解，但是在n=38时，会超出时间限制。。
之后用**动态规划**，时间还算可观，但是只打败了11%的人。
剩下两种不多说了，充满着数学的香气。

### 代码

```python3
import numpy as np
import math


class Solution:
    def climbStairs(self, n: int) -> int:

        # 斐波那契公式
        sqrt5 = math.sqrt(5)
        fibn = math.pow((1+sqrt5) / 2, n+1) - math.pow((1-sqrt5) / 2, n+1)
        return int(fibn // sqrt5)

        '''
        暴力法
        # 超时
        if n == 1:
            return 1
        if n == 2:
            return 2

        return self.climbStairs(n-1) + self.climbStairs(n-2)
        '''

        '''
        动态规划
        # 52 ms	13.6 MB
        if n == 1:
            return 1
        if n == 2:
            return 2
        dp = [1] + [2] + [False] * (n-2)
        # print(dp)
        for i in range(2, n):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[-1]
        '''


    '''
        Binets 方法
        # 120 ms	28.8 MB
        q = np.mat([[1, 1], [1, 0]])
        res = self.matPow(q, n)
        return res.tolist()[0][0]

    def matPow(self, q, n):
        ret = np.mat([[1, 0], [0, 1]])
        while n:
            if n & 1 == 1:
                ret = np.dot(ret, q)
            n >>= 1
            q = np.dot(q, q)
        
        return ret
    '''



        
```