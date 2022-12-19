```
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        d = set()
        for i in range(len(nums)):
            if nums[i] in d:
                return True
            d.add(nums[i])
            if len(d) > k:
                d.remove(nums[i-k])
        return False
```
