### 解题思路
1. 第一种思路就是递归，f(n) = f(n-1) + f(n-2)，递归有很多重复运算，导致超时，不适用
2. 第二种思路就是动态规划，首先我们找到状态转移的公式opt[i] = opt[i-1] + opt[i-2]，同时我们也要找到动态规划的出口，opt[0] = 1, opt[1] = 2，这样就能解决了。

### 代码

```python3
class Solution:
    def climbStairs(self, n: int) -> int:
        # if n == 1:
        #     return 1
        # elif n == 2:
        #     return 2
        # else:
        #     return self.climbStairs(n-1)+self.climbStairs(n-2)
        if n == 1:
            return 1
        elif n == 2:
            return 2
        else:
            opt = [0] * n
            opt[0] = 1
            opt[1] = 2
            for i in range(2, n):
                opt[i] = opt[i-1] + opt[i-2]
        return opt[n-1]
```