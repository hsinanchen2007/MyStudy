### 解题思路
1、因为是排序数列，且每个元素允许出现最多2次；所以直接从第2个元素开始；如果从第3个元素开始，会与下面的while冲突，有bug
2、如果当前元素的数量大于3，则删除当前元素

### 代码

```python
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        index = 1
        while index < len(nums)-1:
            if nums.count(nums[index]) > 2 :
                #del nums[index]
                nums.pop(index)
            else: 
                index = index + 1
        return len(nums)
```