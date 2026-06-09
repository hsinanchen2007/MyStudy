```python
from itertools import combinations
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        return [c for c in combinations(range(1, 10), k) if sum(c) == n]
```
