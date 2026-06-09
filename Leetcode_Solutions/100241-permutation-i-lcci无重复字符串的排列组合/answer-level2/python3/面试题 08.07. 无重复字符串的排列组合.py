
```python []
class Solution:
    def permutation(self, S: str) -> List[str]:
        return map(''.join, itertools.permutations(S))
```