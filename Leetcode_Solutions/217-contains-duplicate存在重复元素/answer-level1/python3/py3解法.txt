```
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        d = set()
        for i in range(len(nums)):
            key = nums[i]
            if key in d:
                return True
            else:
                d.add(key)
```
