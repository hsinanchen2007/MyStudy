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
        n = len(nums)
        return sum([i for i in range(n+1)]) - sum(nums)

```