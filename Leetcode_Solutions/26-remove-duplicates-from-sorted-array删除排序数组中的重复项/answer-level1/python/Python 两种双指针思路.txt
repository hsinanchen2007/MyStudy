```python
# 第一种，如果当前元素与下一个元素不一致，那么就添加到初始指针的位置
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0; nums.append(None)
        for j in range(len(nums) - 1):
            if nums[j] != nums[j + 1]:
                nums[i], i = nums[j], i + 1
        
        return i

# 第二种，将碰到和指针i元素不同的元素，置入指针i + 1所在位置，并移动指针
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        i, j = 0, 1
        while j < len(nums):
            if nums[j] != nums[i]:
                i = i + 1
                nums[i] = nums[j]
            j += 1
        return i + 1
```