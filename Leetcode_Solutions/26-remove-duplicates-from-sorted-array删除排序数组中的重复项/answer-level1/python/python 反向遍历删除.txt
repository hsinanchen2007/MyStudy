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
    
        if len(nums) > 1:   
            for i in range(len(nums)-1,0,-1):
                if nums[i] == nums[i-1]:
                    del nums[i]
    
        #return nums
```