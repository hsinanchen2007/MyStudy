```
from collections import defaultdict


class Solution:
    def longestValidParentheses(self, s: str) -> int:

        m = defaultdict(int)

        for i in range(1, len(s)): m[i] = 2+m[i-1]+m[i-m[i-1]-2] if s[i] == ")" and i-m[i-1]-1 >= 0 and s[i-m[i-1]-1] == "(" else 0

        return max(m.values()) if m else 0
```
