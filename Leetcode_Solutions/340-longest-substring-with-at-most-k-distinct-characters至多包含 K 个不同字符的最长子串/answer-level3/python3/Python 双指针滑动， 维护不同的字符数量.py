
```

'''
双指针滑动，维护区间中不同的字符数量
'''

from collections import Counter
class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        i, j, n = 0, 0, len(s)
        if n == 0 or k == 0:
            return 0

        c = Counter()
        diff_cnt = 1
        c[s[0]] = 1

        ans = 0
        while True:
            while diff_cnt <= k:
                ans = max(ans, j - i + 1)

                if j == n-1:
                    return ans

                j += 1
                if s[j] not in c:
                    c[s[j]] = 1
                else:
                    c[s[j]] += 1
                if c[s[j]] == 1:
                    diff_cnt += 1

            while diff_cnt > k:
                c[s[i]] -= 1
                if c[s[i]] == 0:
                    diff_cnt -= 1
                i += 1
```
