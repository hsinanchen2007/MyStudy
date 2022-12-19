```
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        s= len(collections.Counter(nums))
        if s < len(nums):
            return True
        else:
            return False
```
