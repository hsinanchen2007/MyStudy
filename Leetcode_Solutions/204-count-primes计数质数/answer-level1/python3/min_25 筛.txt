### 解题思路

~~老年退役选手还是能写 min_25 筛的，~~$O(\frac{n ^ \frac{3}{4}}{\log n})$，68ms，为了练习 py，就用 py 写了...

### 代码

``` python
# -*- coding: utf-8 -*-
# min25 sieve


class Solution:
    def countPrimes(self, n: int) -> int:
        if n <= 2:
            return 0
        n -= 1
        M = int(n ** 0.5)
        pre = [0] + [i - 1 for i in range(1, M + 1)]
        suc = [0] + [n // i - 1 for i in range(1, M + 1)]
        for p in range(2, M + 1):
            if pre[p] == pre[p - 1]:
                continue
            pcnt = pre[p - 1]
            q = p * p
            m = n // p
            end = min(M, n // q)
            w = M // p
            for i in range(1, w + 1):
                suc[i] -= suc[i * p] - pcnt
            for i in range(M // p + 1, end + 1):
                suc[i] -= pre[m // i] - pcnt
            for i in range(M, q - 1, -1):
                pre[i] -= pre[i // p] - pcnt
        return suc[1]

```