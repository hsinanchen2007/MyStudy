
### 代码

```python
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            if nums[i] != i:
                return nums[i] - 1
        return len(nums)
```