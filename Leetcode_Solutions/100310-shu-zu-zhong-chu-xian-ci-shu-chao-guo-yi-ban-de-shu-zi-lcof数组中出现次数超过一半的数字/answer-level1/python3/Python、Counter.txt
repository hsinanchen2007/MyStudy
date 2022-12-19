```
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        res=collections.Counter(nums)
        for i in nums:
            if res[i]>(len(nums)/2):
                return i
```
