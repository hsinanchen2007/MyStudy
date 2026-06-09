### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """                  
        for i in range(len(nums)): 
            if nums[i]!=i:
                return i
        return i+1
            
```