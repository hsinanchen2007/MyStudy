### 解题思路
双指针模版是每次end都动，而start是有条件的动
 start, end = 0, 0
        
        while end < len(nums):
            if start<2 or nums[end] != nums[start-2]:
                nums[start] = nums[end];
                start+=1
            end+=1
### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return None
        # if len(nums)<=2:
        #     return indexof(nums[-1])


        start, end = 0, 0
        
        while end < len(nums):
            if start<2 or nums[end] != nums[start-2]:
                nums[start] = nums[end];
                start+=1
            end+=1
        return start
    

```