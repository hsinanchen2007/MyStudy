### 解题思路
如果下一次要到达第i层楼梯有两种可能：1. 从第i-2层向上走2个台阶
                                2.从第i-1层向上走1个台阶
所以到达第i层的次数为： 到达第i-2层的总次数 +到达第i-1 层的总次数

### 代码

```python3
class Solution:
    def climbStairs(self, n: int) -> int:
        # 动态规化：
        dp = [0]*n
        if n ==1 : return 1
        if n ==2 : return 2
        dp[0] = 1
        dp[1] = 2
        for i in range(2,n):
            dp[i] = dp[i-1] +dp[i-2]
            # 这个公式满足斐波那契数
    
        return dp[n-1]
```
```python3
        # 费波纳数求解
        if n ==1 : return 1
        if n ==2 : return 2
        fib1 = 1
        fib2 = 2
        for i in range(3,n+1):
            fib3 = fib1 +fib2
            fib1 = fib2
            fib2 = fib3

        return fib3

```