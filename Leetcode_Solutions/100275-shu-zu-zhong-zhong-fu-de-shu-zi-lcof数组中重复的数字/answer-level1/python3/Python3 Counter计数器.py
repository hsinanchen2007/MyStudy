```
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        c = collections.Counter(nums)
        dup = [k for k,v in c.items() if v > 1]
        return dup[0] if dup else -1
```
