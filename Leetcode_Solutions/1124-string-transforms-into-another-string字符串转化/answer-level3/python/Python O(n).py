最后发现是分情况讨论。。。
```
from string import ascii_lowercase
class Solution:
    def canConvert(self, a: str, b: str) -> bool:
        if len(set(b))==26 and len(set(a))==26 and a!=b:
            return False
        if len(a)!=len(b):
            return False
        d=collections.defaultdict(list)
        for i in range(len(a)):
            d[a[i]].append(i)
        for c in d.keys():
            r=b[d[c][0]]
            for i in d[c]:
                if b[i]!=r:
                    return False
        return True
```
