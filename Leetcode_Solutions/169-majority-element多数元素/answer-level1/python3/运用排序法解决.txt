```
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        p = []
        p = sorted(nums)
        return p[len(nums)//2]
```
