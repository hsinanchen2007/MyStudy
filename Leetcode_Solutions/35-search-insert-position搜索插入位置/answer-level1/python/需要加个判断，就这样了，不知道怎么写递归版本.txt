### 解题思路
范围逐渐缩小，最后返回high

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if nums[0]>=target:
            return 0
        low=0
        high=len(nums)
        while high-low>1:
            medium=low+(high-low)//2
            if nums[medium]==target:
                return medium
            elif nums[medium]>target:
                high=medium
            else:
                low=medium
        return high

```