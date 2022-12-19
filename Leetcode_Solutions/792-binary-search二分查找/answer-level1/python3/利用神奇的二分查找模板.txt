### 解题思路
利用神奇的二分查找模板编写

### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right) >> 1
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid
        return right if nums[right] == target else -1
```