```
class Solution:
    def countAndSay(self, n: int) -> str:
        from itertools import groupby
        from functools import reduce
        return reduce(lambda s,_:''.join(str(sum(1 for _ in it))+k for (k,it) in groupby(s)),range(n-1),'1')
```
