### 解题思路
之前我有个大胆的想法，把target加到nums中，用sort排序，直接返回索引，结果sort显示未定义，只能一步步来了
### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target in nums:
            return nums.index(target)
        else:
            for i in range(len(nums)):
                if target < nums[i]:
                    return i
                    break 
            else:
                if i == len(nums) - 1:
                    return len(nums)

```