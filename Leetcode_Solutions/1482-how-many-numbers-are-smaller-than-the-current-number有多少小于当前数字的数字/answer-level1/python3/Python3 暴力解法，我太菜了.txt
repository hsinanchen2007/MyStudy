```
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        new_nums = []
        for i in nums:
            k = 0
            for j in range(len(nums)):
                if i > nums[j]:
                    k += 1
            new_nums.append(k)
        return new_nums
```
