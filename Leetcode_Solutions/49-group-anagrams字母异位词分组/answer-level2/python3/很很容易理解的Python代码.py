```
from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = dict()
        for s in strs:
            temp = tuple(sorted(s))
            if temp not in d:
                d[temp] = [s]
            else:
                d[temp].append(s)
        res = []
        for i in d.values():
            res.append(i)
        return res
```
