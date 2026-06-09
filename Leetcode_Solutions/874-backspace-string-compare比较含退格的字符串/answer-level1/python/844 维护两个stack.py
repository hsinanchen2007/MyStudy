### 解题思路
维护stack,遇到#就出栈，其他进栈
### 代码

```python
class Solution(object):
    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        stackS = []
        for item in S:
            if item  == '#':
                if stackS != []:
                    stackS.pop()
            else:
                stackS.append(item)
        finalS = ""
        for item in stackS:
            finalS = finalS + item

        stackT = []
        for item in T:
            if item  == '#':
                if stackT != []:
                    stackT.pop()
            else:
                stackT.append(item)
        finalT = ""
        for item in stackT:
            finalT = finalT + item
            
        return finalS == finalT
```