通过堆栈进行左右匹配
```
代码块
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        table = {'(':1,')':-1,'[':2,']':-2,'{':3,'}':-3}
        stack = [0]
        for c in s:
            if stack[-1]+table[c]!=0:
                stack.append(table[c])
            else:
                stack.pop()
        if len(stack)==1:
            return True
        return False
```



