- 先拆分 ( num + 1, ) num -1, 直到为0为一个完整的组合
- 删最外层的括号

```
class Solution(object):
    def removeOuterParentheses(self, S):
        """
        :type S: str
        :rtype: str
        """
        """
        1. 拆分
        2. 删最外层括号
        """
        pos = 0
        num = 0
        Str = ''

        for i, val in enumerate(S):
            if val == '(': 
                num = num + 1
            elif val == ')':
                num = num - 1
            if num == 0 and i != 0:
                Str = Str + S[pos + 1 : i]
                pos = i + 1
        return Str
```
