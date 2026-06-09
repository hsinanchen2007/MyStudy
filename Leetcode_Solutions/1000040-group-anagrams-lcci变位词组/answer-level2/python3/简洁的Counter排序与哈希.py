```
from collections import Counter, defaultdict
class Solution:
    def groupAnagrams(self, strs: [str]) -> [[str]]:
        d = defaultdict(list)
        for s in strs:
            key = tuple(sorted(Counter(s).items()))
            d[key].append(s)
        
        return list(d.values())
```