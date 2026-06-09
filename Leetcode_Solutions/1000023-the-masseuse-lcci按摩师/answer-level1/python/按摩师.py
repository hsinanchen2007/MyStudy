### 解题思路
空间复杂度O（1）

### 代码

```python
class Solution(object):
    def massage(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cur, pre = 0, 0
        for i in range(0, len(nums)):
            cur, pre = max(pre + nums[i], cur), cur
        return cur
```