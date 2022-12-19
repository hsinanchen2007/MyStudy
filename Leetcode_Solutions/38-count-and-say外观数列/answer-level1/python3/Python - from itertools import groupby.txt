```
class Solution:
    def countAndSay(self, n: int) -> str:
        from itertools import groupby
        result = '1'
        for i in range(1,n):
            result = ''.join([str(len(list(g)))+k for k,g in groupby(result)])
        return result
```
