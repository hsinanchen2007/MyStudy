### 解题思路
while start < len(nums) and end < len(nums):

            if nums[start]==nums[end]:
                nums.pop(end)
                continue

            if nums[start]!=nums[end]:
                start+=1
                nums[start] = nums[end]
                end+=1
                continue

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        
        if not nums:
            return None

        start, end = 0, 1
        
        while start < len(nums) and end < len(nums):

            if nums[start]==nums[end]:
                nums.pop(end)
                continue

            if nums[start]!=nums[end]:
                start+=1
                nums[start] = nums[end]
                end+=1
                continue



```