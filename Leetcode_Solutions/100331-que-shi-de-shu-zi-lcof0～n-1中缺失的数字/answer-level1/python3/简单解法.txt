### 解题思路
判断0~n，下标不相等则返回。

### 代码

```python
class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in range(len(nums)):
            if nums[i] != i:
                return i
        return i + 1
        
```