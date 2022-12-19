```
from collections import defaultdict
class Solution:
    def sortString(self, s: str) -> str:
        d = defaultdict(int)
        for i in s:
            d[i] += 1
        positive,negative = [],[]
        for i in sorted(d):
            positive.append([i,d[i]])
        res = ''
        while positive or negative:
            while positive:
                p = positive.pop(0)
                if p[1] >= 1:
                    res += p[0]
                    p[1] -= 1
                    negative.append(p)
            while negative:
                q = negative.pop()
                if q[1] >= 1:
                    res += q[0]
                    q[1] -= 1
                    positive =  [q] + positive
        return res
```
