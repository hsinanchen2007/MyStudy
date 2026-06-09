### 解题思路
v:1 0 2 3 4
i:0 1 2 3 4
遍历到第i个位置时，如果可以分为块，那么前i个位置的最大值一定等于i

### 代码

```python
class Solution(object):
    def maxChunksToSorted(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        res = 0
        m = 0
        for i, v in enumerate(arr):
            m = max(m, v)
            if m == i:
                res = res + 1
        return res

```