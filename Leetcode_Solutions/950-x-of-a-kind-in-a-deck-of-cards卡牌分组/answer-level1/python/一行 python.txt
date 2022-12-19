
```python
import fractions
import functools
class Solution:
    def hasGroupsSizeX(self, deck: 'List[int]') -> 'bool':
        return functools.reduce(fractions.gcd, collections.Counter(deck).values()) > 1
```