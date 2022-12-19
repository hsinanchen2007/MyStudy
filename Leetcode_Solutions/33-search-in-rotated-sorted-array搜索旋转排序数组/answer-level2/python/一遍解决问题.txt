### 解题思路
先判断target大小是不是比最左数大
然后二分查找的比较条件中，再增加一个根据nums[mid]与nums[left]或nums[right]的比较
### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums: return -1
        left, right = 0, len(nums) - 1
        if nums[right] < target < nums[left]: return -1
        if target >= nums[left]: 
            left_part = True
        else:
            left_part = False
        while left <= right:
            mid = (left + right) // 2
            if left_part:
                if target < nums[mid] or nums[mid] < nums[left]:
                    right = mid - 1
                elif target > nums[mid]:
                    left = mid + 1
                else:
                    return mid
            else:
                if target > nums[mid] or nums[mid] > nums[right]:
                    left = mid + 1
                elif target < nums[mid]:
                    right = mid - 1
                else:
                    return mid
        return -1
```