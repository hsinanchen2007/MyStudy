### 解题思路
求大佬优化。
### 代码
```python
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:return len(nums)
        else:
            ind = 0
            while ind < len(nums)-1:
                if nums[ind]==nums[ind+1]:nums.pop(ind)
                else:ind+=1
            return len(nums) 
```