### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def addToArrayForm(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: List[int]
        """
        
        return [ int(x) for x in  str(int("".join(list(map(str,A))))+K)]
```