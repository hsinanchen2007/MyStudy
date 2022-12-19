```
class Solution:
    def largestUniqueNumber(self, A: List[int]) -> int:
        # using collections.Counter
        from collections import Counter
        ans = -1
        for k, v in Counter(A).items():
            if v == 1:
                ans = max(ans, k)
        return ans
```
