### 解题思路
因为时间复杂度为为O(logn)，所以采用二分查找法。

### 代码

```python3
def SearchRange(nums, target, left, right):
    
    if left > right:
        return [-1, -1]
    if left == right:
        if nums[left] == target:
            return [left, left]
        else:
            return [-1, -1]
    middle = (left + right + 1) // 2
    if nums[middle] == target:
        begin = middle
        end = middle
        while (begin - 1) >= left and nums[begin-1] == nums[begin] :
            begin -= 1
        while (end + 1) <= right and nums[end+1] == nums[end] :
            end += 1
        return [begin, end]
    elif nums[middle] > target:
        right = middle - 1
        return SearchRange(nums, target, left, right)
    else:
        left = middle + 1
        return SearchRange(nums, target, left, right)

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        return SearchRange(nums, target, 0, len(nums)-1)

```