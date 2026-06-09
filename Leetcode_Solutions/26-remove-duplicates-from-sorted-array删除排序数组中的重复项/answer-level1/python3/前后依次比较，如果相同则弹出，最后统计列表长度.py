### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)<1:
            return len(nums)
        i=0
        while i<len(nums)-1:
            if nums[i]==nums[i+1]:
                nums.pop(i)
            else:
                i+=1
        return len(nums)

```