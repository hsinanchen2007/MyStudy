### 解题思路


### 代码

```python
class Solution(object):
    def generatePossibleNextMoves(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        h = []
        for i in range(len(s)-1):
            if s[i]=='+' and s[i+1] =='+':
                h.append(s[:i]+"--"+s[i+2:])
        return h




```