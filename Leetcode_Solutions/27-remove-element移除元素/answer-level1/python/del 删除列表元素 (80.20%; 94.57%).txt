### 解题思路
直接用del 删除list元素。注意len(list)是变化的。

### 代码

```python
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        if len(nums)==0:
            return 0
        i=0
        # 使用for循环需要注意应对len(nums)的变化
        while i < len(nums):
            if nums[i] == val:
                del nums[i]
            else:
                i = i+1
        return len(nums)
        
```