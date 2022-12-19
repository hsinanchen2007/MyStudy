### 解题思路
纯index 列表定位法

### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if target not in nums:
            return [-1,-1]
        x = nums.index(target)
        nums.reverse()
        y = nums.index(target)
        return [x,len(nums)-1-y]
```