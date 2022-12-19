### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def isLongPressedName(self, name, typed):
        """
        :type name: str
        :type typed: str
        :rtype: bool
        """
        p=0
        q=0
        while p<len(name) and q<len(typed):
            if name[p]==typed[q]:
                q+=1
                p+=1
            else:
                q+=1
        return p==len(name)
```