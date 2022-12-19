1. 注意数组是否为空
2. 原数组是递增的，根据起止值和中间值判断，缩小判断范围，最后得到解
```
class Solution:
    def findMin(self, nums: List[int]) -> int:
        if not nums:
            return None
        l = len(nums)
        if l == 1:
            return nums[0]
        mid = int(l/2)
        last_value = nums[-1]
        mid_value = nums[mid]
        start_value = nums[0]
        if last_value > mid_value and mid_value < start_value:
            ans = self.findMin(nums[:mid+1])
        elif last_value < mid_value and mid_value > start_value:
            ans = self.findMin(nums[mid:])
        else:
            ans = min(mid_value, last_value, start_value)
        return ans
```