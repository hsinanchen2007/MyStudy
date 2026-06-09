```
from collections import Counter
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        counter = Counter(deck)
        c = [val for val in counter.values()]

        g = c[0]
        for i in range(1, len(c)):
            g = self.god(g, c[i])

        return g >= 2

    # 求最大公约数
    def god(self, p, q):
        if q == 0:
            return p

        return self.god(q, p % q)
```
