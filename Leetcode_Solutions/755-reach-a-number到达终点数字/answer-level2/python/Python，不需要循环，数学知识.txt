```python
from math import ceil
class Solution:
    def reachNumber(self, target: int) -> int:
        target = abs(target)
        x = ceil(-0.5+(1+8*target)**0.5/2)  # 先计算1+2+3+...+x>=target的最小值，用的是一元二次方程求根公式
        if (x*x+x-2*target)/2 % 2:  # 超过target的步数为奇数
            if x % 2:  # x为奇数
                return x+2  # 则需要再走两下才能将超出变为偶数，再将之前的某次或些行走翻转方向便能减去这部分超出
            return x+1  # x为偶数则只需再走一下（x+1为奇数）将超出变成偶数，再将之前的某次行走翻转方向即可
        return x  # 超过target的步数为偶数，则将之前某次行走翻转方向就能减去这部分超出

```
