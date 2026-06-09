所求数组必是等差数列，数列求和，i表示数列的开头， n表示数列长度，有:
target = (2i-1)n +n^2 = 2target
由于i, n 是正整数, 所以 n_max=int((2target)**0.5)(这里简化了一下)，接下来就简单了，从n_max一直减到2，计算i ，当i是整数时 把对应的数列写出来，就完事了。代码如下：
```
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        res = []
        for n in range(int((2 * target)**0.5), 1, -1):
            i = ((2 *target - n**2) / n + 1) /2
            if i == int(i):
                buf = [int(i+j) for j in range(0, n)]
                res.append(buf)
        return res

```

