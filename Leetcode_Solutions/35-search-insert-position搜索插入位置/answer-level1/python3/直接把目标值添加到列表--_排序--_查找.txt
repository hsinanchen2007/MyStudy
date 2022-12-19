### 解题思路
直接把目标值添加到列表-->排序-->查找
时间复杂度：o(n)
空间复杂度：o(1)
### 代码

```python
class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.append(target)
        nums.sort()
        for i,j in enumerate(nums):
            if j==target:
                return i
```