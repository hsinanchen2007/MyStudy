### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        for i in range(len(nums)):
            if nums[i] == target:
                return i
            elif min(nums) > target:
                return 0
            elif max(nums) <target:
                return len(nums)
            elif nums[i]<target and nums[i+1]>target:
                return i+1

```