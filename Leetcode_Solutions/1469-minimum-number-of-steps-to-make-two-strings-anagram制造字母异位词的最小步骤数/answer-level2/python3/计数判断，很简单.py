```
class Solution:
    def minSteps(self, s: str, t: str) -> int:
        from collections import Counter
        cnt_s = Counter(list(s))
        cnt_t = Counter(list(t))
        res = 0
        for i in cnt_s:
            if i not in cnt_t:
                res += cnt_s[i]
            if i in cnt_t and cnt_s[i] > cnt_t[i]:
                res += cnt_s[i] - cnt_t[i]
        return res
```
