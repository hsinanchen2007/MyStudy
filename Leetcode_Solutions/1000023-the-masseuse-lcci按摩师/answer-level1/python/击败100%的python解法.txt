### 解题思路
动态规划 
cur = 0
pre = 0
res = max(cur,pre + nums[i])

### 代码

```python
class Solution(object):
    def massage(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        pre = 0
        cur = 0
        res = 0

        for i in nums:
            res = max(cur,pre + i)
            pre = cur
            cur = res
        return res
```