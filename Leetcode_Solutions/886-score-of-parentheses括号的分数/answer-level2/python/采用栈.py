# 遇到‘(’，则将ss入栈，并置为0；
# 遇到‘）’，将将ss乘以2，并加上一个出栈的数据；
# 遇到1，则直接加

```
class Solution(object):
    def scoreOfParentheses(self, S):
        """
        :type S: str
        :rtype: int
        """
        S = S.replace('()', '1')
        stack1 = list()
        stack2 = list()
        ss = 0
        for c in S:
            if c == '(':
                stack1.append(ss)
                ss = 0
            elif c == ')':
                ss = ss * 2 + stack1.pop()
            else:
                ss += int(c)
        return ss
```

    
