思路：
- 使用栈，每逢左括号则必压栈；
- 每逢右括号则出栈与其匹配，匹配成功则继续，否则立刻判无效；
- 最后若栈空则返回true

```
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        pairs = {'(':')','[':']','{':'}'}
        keys = ['(','[','{']
        queue = list(s)
        stack = []
        for c in queue:
            if c in keys:          #左括号压栈
                stack.append(c)
            else:
                if stack:          #右括号检查匹配则出栈左括号，否则非法
                    if pairs[stack.pop()] == c:
                        continue
                    else:
                        return False
                else: return False   
        return len(stack)==0
```
