### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        low = 0
        high = len(nums)
        while low < high:
            mid = low + (high - low)//2
            if nums[mid] > target:
                high = mid
            elif nums[mid] < target:
                low = mid +1
            else:
                return mid
        return low
```