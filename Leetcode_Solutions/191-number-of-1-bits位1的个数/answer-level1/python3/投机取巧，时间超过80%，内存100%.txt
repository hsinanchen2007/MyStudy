```
from collections import Counter
class Solution:
    def hammingWeight(self, n: int) -> int:
        cnt = Counter(list(str(bin(n))))
        return dict(cnt.most_common()).get('1') if dict(cnt.most_common()).get('1') else 0
```
