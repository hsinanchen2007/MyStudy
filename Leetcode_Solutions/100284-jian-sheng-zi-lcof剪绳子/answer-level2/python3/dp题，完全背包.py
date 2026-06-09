这个题是个典型的dp。

不难理解的是，对一个长度为i的绳子，想要结果最大，一定是对一个长度j，有

$$
dp[i] = \max_{1<=j<n}(dp[j] * dp[i - j])
$$

所以，自底向上的考虑的话，只要能得出剪开后每个短绳子的最大值，最后的结果就可以得到。
我们有几个简单的情况，长度在2,3时结果分别是1和2。从i=4开始向上计算。

```python
class Solution:
    def cuttingRope(self, n: int) -> int:
        result = [0, 1, 2, 3]
        if n < 2:
            return -1
        if n == 2:
            return 1
        if n == 3:
            return 2
        for i in range(4, n + 1):
            m = 0
            for j in range(1, i // 2 + 1):
                tmp = result[j] * result[i - j]
                if tmp > m:
                    m = tmp
            result.append(m)
        return result[n]
```