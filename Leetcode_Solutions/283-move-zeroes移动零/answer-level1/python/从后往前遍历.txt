### 解题思路
一开始采用从前往后遍历，但这样子会有一个问题—：删除第i元素之后，后面元素自动前移，如果从前往后遍历会遗漏掉第i+1个元素，因此改成从后往前遍历。

### 代码

```python
class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        #i = 0
        i = len(nums)-1
        while i >= 0:
            if nums[i] == 0:               
                del nums[i]
                nums.append(0)
            i -= 1
           
            
```