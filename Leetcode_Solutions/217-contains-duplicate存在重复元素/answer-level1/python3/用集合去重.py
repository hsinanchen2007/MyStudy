### 解题思路
用集合去重，然后比较长度确认是否存在重复的元素

### 代码

```python
class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        return len(set(tuple(nums))) < len(nums)
```