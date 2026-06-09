```python
from collections import defaultdict


class Solution:
    def numTrees(self, n: int) -> int:
        record = defaultdict(int)

        def _count(l, r):
            if l > r: return 1
            
            if (l, r) not in record:
                for i in range(l, r + 1):
                    record[l, r] += _count(l, i - 1) * _count(i + 1, r)

            return record[l, r]

        return _count(1, n)
```