### 代码

```python
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        def match(left,right):
            opens="([{"
            closers=")]}"
            return opens.index(left)==closers.index(right)
        stack=[]
        index=0
        while index < len(s):
            if s[index] in "([{":
                stack.append(s[index])
            else:
                if not stack:
                    return False 
                top=stack.pop()
                if not match(top,s[index]):
                    return False   
            index=index+1
        return not stack
```