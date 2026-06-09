![image.png](https://pic.leetcode-cn.com/ada0e4fb8fb6c7f7901e7a6ce8ea04e41dcd0cd8ac8df0fbe8ab50fcee9ce76a-image.png)

行列分别记录奇偶值，输出时取奇偶相交的行输出，这里实际上是把公式针对求和的表达式以减少`sum`运算为目来化简了，36ms仅供参考。

```python []
class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        r, c = [False] * n, [False] * m
        for x, y in indices:
            r[x] ^= True
            c[y] ^= True
        return int((m - 2 * sum(c)) * (sum(r) - n / 2) + m * n / 2)
```
