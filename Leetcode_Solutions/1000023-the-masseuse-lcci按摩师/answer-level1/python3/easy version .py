### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        if not nums:
            return 0 
        if len(nums) == 1:
            return nums[0]
        best = [0] * len(nums)
        best[0] = nums[0]
        best[1] = max(nums[0],nums[1])
        for i in range(2,len(nums)):
            best[i] = max(best[i-1],best[i-2] + nums[i])
        return max(best)
```