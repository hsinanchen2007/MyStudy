### 解题思路
感觉从后向前简单一点。

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        nums[n-2] = max(nums[n-2],nums[n-1])
        for i in range(n-3,-1,-1):
            nums[i] = max(nums[i+1],nums[i] + nums[i+2])
        return nums[0]
```