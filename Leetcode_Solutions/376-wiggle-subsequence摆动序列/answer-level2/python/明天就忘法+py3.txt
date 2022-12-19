### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        n=len(nums)
        if not nums:
            return 0
        low=1
        high=1
        for i in range(1,n):
            if nums[i]>nums[i-1]:
                low=high+1
            elif nums[i]<nums[i-1]:
                high=low+1
        return max(low,high)
```