```
class Solution:
    def translateNum(self, num: int) -> int:
        nums, a, b = list(map(int, str(num))), 1, 1
        for i in range(2, len(nums) + 1):
            a, b = b, b + (10 <= 10 * nums[i-2] + nums[i-1] <= 25) * a
        return b
```
