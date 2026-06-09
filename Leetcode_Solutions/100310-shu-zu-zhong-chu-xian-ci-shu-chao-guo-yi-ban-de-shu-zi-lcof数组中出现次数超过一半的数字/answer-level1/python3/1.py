```
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        if len(nums) ==1: return nums[0]
        cur = nums[0]
        count = 1
        for i in range(1, len(nums)):
            if nums[i] == cur:
                count += 1
            else:
                count -= 1
                if count == 0:
                    count = 1
                    cur = nums[i]
        return cur
```
