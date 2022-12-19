### 解题思路

1. !|& 直接放入stack
2. ft 追加到stak最后一个元素后面(第一个一定是操作符，后面都是ft)
3. 遇到), 取出上一个元素， 进行相应判断

### 代码

```python
class Solution(object):
    def parseBoolExpr(self, expression):
        """
        :type expression: str
        :rtype: bool
        """
        stack = ['']
        for ch in expression:
            if ch in 'ft':
                stack[-1] += ch
            elif ch in '!|&':
                stack.append(ch)
            elif ch == ')':
                opchs = stack.pop()
                op, chs = opchs[0], opchs[1:]
                sch = 'f'
                if op == '!':
                    if chs == 'f':
                        sch = 't'
                elif op == '|':
                    if 't' in chs:
                        sch = 't'
                elif op == '&':
                    sch = 't'
                    if 'f' in chs:
                        sch = 'f'
                stack[-1] += sch

        return True if stack[0] == 't' else False
```