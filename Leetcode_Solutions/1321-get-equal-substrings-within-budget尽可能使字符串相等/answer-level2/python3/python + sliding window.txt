```python
class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        # s  =  'abcd'
        # t  =  'bcdf'
        # maxCost = 3
        # windows_condition = maxCost

        # Time complexity : O(N)
        # Space complexity: O(1)

        res, j, cost = 0, 0, 0
        for i in range(len(s)):
            if s[i] != t[i]: cost += abs(ord(s[i]) - ord(t[i]))
            while cost > maxCost:
                cost -= abs(ord(s[j]) - ord(t[j]))
                j += 1
            res = max(res, i + 1 - j)
        return res
```