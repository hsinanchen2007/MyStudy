```
class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        # 最大三个数, 要么都是正数, 要么是两个负数+一个正数
        nums.sort()
        return max(nums[-1] * nums[-2] * nums[-3], nums[0] * nums[1] * nums[-1])
```
