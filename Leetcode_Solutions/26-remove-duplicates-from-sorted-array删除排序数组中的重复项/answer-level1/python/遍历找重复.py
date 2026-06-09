### 解题思路
代码简单、思路清晰

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        index = 0
        while index < len(nums)-1:
            if nums[index] == nums[index+1]:
                nums.remove(nums[index+1])
            else:
                index += 1
        return len(nums)
```