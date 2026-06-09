![图片1.png](https://pic.leetcode-cn.com/81c8a0ae1c81df394e0437994b987d26b2c3d8bfdcb4be8bd26b5258d951b556-%E5%9B%BE%E7%89%871.png)

```
# 图示两种情况独立，分为第n个和第n-1个方块颜色相同与否。
class Solution:
    def numWays(self, n: int, k: int) -> int:
        if n==0: return 0
        elif n==1: return k
        elif n==2: return k**2
        else:
            dp = list()
            dp.append(k)
            dp.append(k**2)
            for i in range(2,n):
                dp.append(dp[i-2]*(k-1) + dp[i-1]*(k-1))
            return dp[-1]
```
