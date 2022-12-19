### 解题思路

只需要统计$n!$中一共多少个5即可。因为只有2和5能凑出10，而且2的个数一定是多于5的

然后利用数论中的公式有$\sum_{i=1}^{\inf}[\frac{n}{5^i}]$ 即可求出。

### 代码

```python3
class Solution:
    def trailingZeroes(self, n: int) -> int:
        n_5 = 0
        while n:
            n_5 += (n // 5)
            n = n // 5
        return n_5
```