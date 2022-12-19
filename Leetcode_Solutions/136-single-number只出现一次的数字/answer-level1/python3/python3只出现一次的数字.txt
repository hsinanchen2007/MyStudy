```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        r=0
        for num in nums:
            r^=num
        return r
```
