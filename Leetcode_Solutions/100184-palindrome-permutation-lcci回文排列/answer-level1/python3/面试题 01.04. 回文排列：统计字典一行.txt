

```python []
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        return len([0 for v in collections.Counter(s).values() if v % 2]) <= 1
```