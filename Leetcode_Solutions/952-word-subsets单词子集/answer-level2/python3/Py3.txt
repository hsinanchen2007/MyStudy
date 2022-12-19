```python3 []
class Solution:
    def wordSubsets(self, A: List[str], B: List[str]) -> List[str]:
        from functools import reduce
        C = reduce(operator.__or__, map(collections.Counter, B))
        return filter(lambda a: not C - collections.Counter(a), A)
```
