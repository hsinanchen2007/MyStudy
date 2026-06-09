### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        l_num = len(nums)
        for i in range(l_num):
            if nums[i]==target:
                return i
            elif nums[i]>target:
                return i
        return i+1 
            
```