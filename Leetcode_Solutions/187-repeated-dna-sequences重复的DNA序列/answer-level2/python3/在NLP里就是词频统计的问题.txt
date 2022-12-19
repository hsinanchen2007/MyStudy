使用默认词典就行了
```
from collections import defaultdict
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        fre = defaultdict(int)
        for local in range(0, len(s)-9, 1):
            fre[s[local:local+10]]+=1
        return [k for k,v in fre.items() if v>=2]
```
