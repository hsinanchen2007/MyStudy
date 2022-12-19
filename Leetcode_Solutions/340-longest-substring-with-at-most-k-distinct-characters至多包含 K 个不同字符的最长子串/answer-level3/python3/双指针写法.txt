```
from collections import Counter


class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        ans = 0
        if len(s) < 1 or k == 0:
            return 0

        sliding_win = Counter()
        left, right = 0, 0
        n, cur_k = len(s), 0

        while True:
            while right < n:
                if sliding_win[s[right]] == 0:
                    if cur_k == k:
                        break
                    cur_k += 1
                sliding_win[s[right]] += 1
                right += 1

            ans = max(ans, right - left)
            if cur_k < k or right == n:
                break

            sliding_win[s[left]] -= 1
            if sliding_win[s[left]] == 0:
                cur_k -= 1
            left += 1
        return ans
```
