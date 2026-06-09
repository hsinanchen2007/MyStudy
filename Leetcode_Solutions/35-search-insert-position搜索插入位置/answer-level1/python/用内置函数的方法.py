### 解题思路
若在则返回下标，不在就添进、排序、返下标

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target in nums:
            return nums.index(target)
        nums.append(target)
        nums = sorted(nums)
        return nums.index(target)
        
```