- python调包侠 funtools, fractions, collections
- 会各种高级函数map(), reduce(), filter()
- 先理解题意
```
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        # 1. brute force
        # from collections import Counter
        # ret = Counter(deck)
        # for i in range(2, len(deck)+1):
        #     if len(deck) % i == 0:
        #         if all(v % i == 0 for v in ret.values()):  # 
        #             return True
        # return False
        
        
        # 2.maxinum common divisor
        from functools import reduce
        from collections import Counter
        from fractions import gcd
        values = Counter(deck).values()
        return reduce(gcd, values) >=2
```
