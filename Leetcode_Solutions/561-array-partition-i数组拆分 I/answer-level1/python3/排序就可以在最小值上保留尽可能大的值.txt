```
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        if len(nums) < 1:
            return 0
        nums.sort()
        count = 0
        for i in range(0, len(nums), 2):
            count += nums[i]
        return count

```
