```
from collections import Counter


class Solution:
    def longestPalindrome(self, s: str) -> int:
        s_counter = Counter(s)
        fix = 0
        res = 0
        for k in s_counter:
            if s_counter[k] % 2 == 0:
                res += s_counter[k]
            else:
                fix = 1
                res += s_counter[k] - 1
        return res + fix
```
