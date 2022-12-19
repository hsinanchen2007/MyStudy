### 解题思路
97.91%
同官方最大公约数算法一样，不过是手写的...

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        def gcd(a, b):
            m = a % b
            while m != 0:
                a = b
                b = m
                m = a % b
            return b

        if len(deck) == 1:
            return False
        lst = list(collections.Counter(deck).values())
        a = lst[0]
        for x in range(1, len(lst)):
            g = gcd(a, lst[x])
            if g < 2:
                return False
            a = g
        return True
     
```