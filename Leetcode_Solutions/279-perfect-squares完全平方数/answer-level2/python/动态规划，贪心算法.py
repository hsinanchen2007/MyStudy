
```python []
class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        # 创建状态表，减少计算量
        dp = {}
        def dp_process(val):
            if val in dp:
                return dp[val]
            if val == 0:
                return 0
            num = int(val ** 0.5)
            min_len = float("inf")
            for i in range(num, 0, -1):
                # 求余，剩下的值用于下个状态计算
                min_len = min(dp_process(val % (i * i)) + val // (i * i), min_len)
            dp[val] = min_len    
            return min_len
        
        return dp_process(n)
```

`