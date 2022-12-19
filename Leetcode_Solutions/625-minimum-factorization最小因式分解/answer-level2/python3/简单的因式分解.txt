首先a如果小于10肯定就是本身
之后从大往小开始因式分解，避免9被分解成3*3这种情况，题目需要分解的因数都是个位数且位数最少，然后才是最小
所以最后把str的因数数组逆序串起来，判断一下临界就行

```
class Solution:
    def smallestFactorization(self, a: int) -> int:
        if a < 10:return a
        factor = []
        for i in range(9, 1, -1):
            while a % i == 0:
                factor.append(str(i))
                a //= i
        if a != 1:return 0
        res = int("".join(factor[::-1]))
        return res if res < 2 ** 31 else 0
```
