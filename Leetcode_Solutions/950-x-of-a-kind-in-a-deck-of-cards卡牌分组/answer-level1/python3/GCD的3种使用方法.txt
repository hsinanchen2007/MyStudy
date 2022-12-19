使用Python3的Counter+gcd+reduce可以很好地解决本题，但gcd可以有3种写法：
1. 实现辗转相除法
2. 从fractions导入
3. 从math导入

代码如下：
```python
    # gcd: O(nlogc), O(n) (c is the range of deck)
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        from collections import Counter
        from functools import reduce
        # Greatest Common Divider
        def gcd(a, b):
            return b if a % b == 0 else gcd(b, a % b)

        # from fractions import gcd
        # from math import gcd
        counts = Counter(deck).values()
        return reduce(gcd, counts) >= 2
```