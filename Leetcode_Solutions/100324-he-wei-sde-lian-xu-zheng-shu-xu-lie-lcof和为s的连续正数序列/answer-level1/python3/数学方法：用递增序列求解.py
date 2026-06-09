### 解题思路

穷举法。

假设序列 $x, x+1, x+2, ..., x+n$ 之和为$s$。则有

$$n(n+1)/2 + (n+1) x = s$$

可以得到$x$的表达式

$$x = s/(n+1) - n/2$$

限制$n$从$1$到$s-1$，穷举可能的整数$x$。

### 代码

```python3
# -*- coding:utf-8 -*-
class Solution:
    def FindContinuousSequence(self, tsum):
        # write code here
        res = []
        for n in range(1, tsum):
            x = tsum / (n + 1) - n / 2
            if x > 0 and int(x) == x:
                res.append([int(x) + i for i in range(n + 1)])
        return res[::-1]
```

时间复杂度：O(n)