### 解题思路
主要的是首先判断是否插入首尾的边界情况，当处理完边界情况后，即是常规的单指针从前向后遍历。

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if len(nums) == 0 or target <= nums[0]:
            return 0
        elif target > nums[-1]:
            return len(nums)
        elif target == nums[-1]:
            return len(nums) - 1
        else:
            p = 0
            while p < len(nums):
                if target == nums[p]:
                    return p
                elif target > nums[p]:
                    p += 1
                    continue
                else:
                    return p

```