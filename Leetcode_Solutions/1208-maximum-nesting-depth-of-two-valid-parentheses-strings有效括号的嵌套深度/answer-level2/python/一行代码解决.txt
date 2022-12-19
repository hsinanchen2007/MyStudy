### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def maxDepthAfterSplit(self, seq):
        """
        :type seq: str
        :rtype: List[int]
        """
        return [i & 1 ^ (seq[i] == ')') for i, c in enumerate(seq)]
```