
```python []
class Solution:
    def longestPalindrome(self, s: str) -> int:
        ans = sum(t - t % 2 for t in collections.Counter(s).values())
        return ans + (ans != len(s))
```