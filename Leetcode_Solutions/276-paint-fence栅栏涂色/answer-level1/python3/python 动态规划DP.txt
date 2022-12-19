当n=1时，有k种不同涂法
当n=2时，有k * k 种不同涂法（此时还不用考虑连续相邻两个相同的问题）
当n>2时：
设定paint(i), i>2 为第i张海报的涂法, 则我们需要考虑两种情况：
    1. 如果和前一张海报涂色相同：则有paint(i-2) * (k-1)种涂法
    2. 如果和梁遗址海报的涂色不同：则有paint(i-1) * (k-1)种涂法
所以DP的状态方程可以表示为:
**paint(i) = (paint(i-2)+paint(i-1))*(k-1)**
用lru_cache代替了数组来存储DP状态，代码如下
```
from functools import lru_cache
class Solution:
    def numWays(self, n: int, k: int) -> int:
        if n == 0 :
            return 0       
        @lru_cache(None)
        def paint(i):
            if i==2:
                return k*k
            if i== 1:
                return k
            return (paint(i-2)+paint(i-1))*(k-1)
        return paint(n)
```
