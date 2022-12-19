同习题 [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/solution/gelthin-jie-sheng-kong-jian-yong-dict-by-gelthin/)

思路很像。
最开始用蛮力递归， 后来用 DP, 但DP 数组太多，后来用带存储值的递归，但只计算部分状态。

注意状态转移方程， 
+ DP[n] = DP[n-coin] +1 
+ 而不是DP[n] = min( DP[x] + DP[i-x] for x in range(n))
也即不需要去枚举所有的DP 前的状态 

按照官方题解所说，下面代码在 python2 可以过，但 python3 过不了很奇怪。
官方题解还提供了很多其他的做法，非常巧妙。

``` python3
class Solution:
    def numSquares(self, n: int) -> int:
        # DP = [x for x in range(n+1)] # 初始化为 [1,2,3,4,5,6]
        # # DP[0] = 0 # s.t. DP[val] = 1
        
        # import math
        # t = int(math.sqrt(n))
        # vals = [x**2 for x in range(1, t+1)]  # 一个可能的完全平方数

        # for i in range(1, n+1):  # 效率可能有点低， 5374 超时
        #     j = 0
        #     while j < len(vals) and vals[j] <= i:
        #         DP[i] = min(DP[i], 1 + DP[i-vals[j]])
        #         j += 1
        # return DP[n]

        def helper(n, DP, vals):
            if DP[n] != -1:
                return DP[n]
            else:
                j = 0
                DP[n] = n # 初始化
                while j < len(vals) and vals[j] <= n:
                    DP[n] = min(DP[n], 1 + helper(n-vals[j], DP, vals))
                    j += 1
                return DP[n] 
        
        # 用递归吧，只对部分可能值计算, 但递归引入了一个自顶向下的过程，可能减速  # 8609 仍旧超时
        DP = [-1 for x in range(n+1)]
        DP[0] = 0
        import math
        t = int(math.sqrt(n))
        vals = [x**2 for x in range(1, t+1)] 
        return helper(n, DP, vals)
```

