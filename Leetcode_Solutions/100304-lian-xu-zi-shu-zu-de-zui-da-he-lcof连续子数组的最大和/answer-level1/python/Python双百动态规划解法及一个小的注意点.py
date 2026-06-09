Python双百，要注意的问题是：（如果从第二个开始遍历）max_val的初始值要设置为nums[0]而不是负的inf，不然nums[0]不会被遍历到
```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        length = len(nums)
        if length == 1:
            return nums[0]

        max_val = nums[0]
        for i in range(1, length):
            nums[i] += max(0, nums[i-1])
            max_val = max(max_val, nums[i])
        
        return max_val
```
