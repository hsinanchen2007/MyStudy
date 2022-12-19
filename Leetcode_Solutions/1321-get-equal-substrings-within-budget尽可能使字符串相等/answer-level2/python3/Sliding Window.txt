```
class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        max_len, l, sum_cost = 0, 0, 0
        for r in range(len(s)):
            sum_cost += abs(ord(s[r]) - ord(t[r]))
            while sum_cost > maxCost:
                sum_cost= sum_cost - abs(ord(s[l]) - ord(t[l]))
                l += 1
            max_len = max(max_len, r - l + 1)
        return max_len
```
