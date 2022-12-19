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
        N = len(nums)
        sums = (N + 1) * (0 + N) >> 1
        return sums - sum(nums)
```