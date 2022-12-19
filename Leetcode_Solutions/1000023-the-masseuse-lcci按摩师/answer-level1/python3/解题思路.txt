### 解题思路
递推公式：
    max_inc[i] = max(max_exc[i - 1] + nums[i], max_inc[i - 1])
    max_exc[i] = max(max_inc[i - 1], max_exc[i - 1])

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        size = len(nums)
        if size == 0:
            return 0
        if size == 1:
            return nums[0]
        if size == 2:
            return max(nums)
        max_inc = [0 for i in range(size)]
        max_exc = [0 for i in range(size)]
        max_inc[0] = nums[0]
        max_inc[1] = max(nums[0], nums[1])
        max_exc[0] = 0
        max_exc[1] = max_inc[0]
        for i in range(2, size):
            max_inc[i] = max(max_exc[i - 1] + nums[i], max_inc[i - 1])
            max_exc[i] = max(max_inc[i - 1], max_exc[i - 1])
        return max(max_inc[-1], max_exc[-1])
```