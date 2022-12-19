### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """

        return not (len(nums) == len(set(nums)))
```