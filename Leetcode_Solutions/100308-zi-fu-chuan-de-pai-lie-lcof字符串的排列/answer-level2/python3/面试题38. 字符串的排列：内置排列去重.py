
```python []
class Solution:
    def permutation(self, s: str) -> List[str]:
        return {*map(''.join, itertools.permutations(s))}
```