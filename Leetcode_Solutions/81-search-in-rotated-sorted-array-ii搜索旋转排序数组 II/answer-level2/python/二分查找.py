### 解题思路
- nums[mid] == target
- l-mid升序：nums[l] < nums[mid]
- mid-r升序：nums[l] > nums[mid]
- nums[l] == nums[mid]的时候就是13112这种情况，l右移一位
### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        l = 0
        r = len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] == target:
                return True
            elif nums[l] < nums[mid]:
                if nums[l] <= target < nums[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
            elif nums[l] > nums[mid]:
                if nums[mid] < target <= nums[r]:
                    l = mid + 1
                else:
                    r = mid - 1 
            # 相等的情况就得讨论
            else:
                l += 1
        return False
```