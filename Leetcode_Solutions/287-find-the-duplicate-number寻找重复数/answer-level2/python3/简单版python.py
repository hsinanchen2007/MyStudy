### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def findDuplicate(self,nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        for i in range(1, len(nums)):
            if (nums[i]==nums[i-1]):
                return nums[i]
```