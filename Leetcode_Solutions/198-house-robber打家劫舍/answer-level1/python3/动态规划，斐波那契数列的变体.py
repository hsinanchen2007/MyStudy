长度比原始数组加一是要考虑边界条件

```
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        if len(nums) == 0:
            return 0
        if len(nums) == 2:
            return max(nums)

        money = [0] * (len(nums) + 1)
        money[1] = nums[0]
        money[2] = max(nums[:2])
        for i in range(3, len(nums) + 1):
            money[i] = nums[i - 1] + max(money[i - 2], money[i - 3])
        return max(money[-1], money[-2])
```
