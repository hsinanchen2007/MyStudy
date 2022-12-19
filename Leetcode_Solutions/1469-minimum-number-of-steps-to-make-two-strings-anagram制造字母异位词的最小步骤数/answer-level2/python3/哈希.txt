```
class Solution:
    def minSteps(self, s: str, t: str) -> int:
        ans=0
        cnt_s=collections.Counter(s)
        cnt_t=collections.Counter(t)
        for k,v in cnt_s.items():
            if v>cnt_t[k]:
                ans+=(v-cnt_t[k])

        return ans

```
