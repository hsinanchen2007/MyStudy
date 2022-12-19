```Python
class Solution:
    def flipgame(self, fronts: List[int], backs: List[int]) -> int:
        return min(set(fronts+backs)-{i for i, j in zip(fronts, backs) if i == j} or [0])
```
跟……跟风？