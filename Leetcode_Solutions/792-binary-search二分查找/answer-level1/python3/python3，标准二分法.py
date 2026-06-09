### 解题思路
标准的二分法查找，没啥特别的。

### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0 , len(nums)-1
        while left < right:
            mid = (left + right)>>1
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid
        return left if nums[left] == target else -1
```