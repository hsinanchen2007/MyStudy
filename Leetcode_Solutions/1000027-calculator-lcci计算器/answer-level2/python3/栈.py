使用一个stack
对于*和/, 直接计算并把结果压回stack
对于+和-, 统一在最后计算
```python
class Solution:
    def calculate(self, s: str) -> int:
        stack = []
        cur = ''
        res = 0
        for i in range(len(s) + 1):
            c = 'E' if i >= len(s) else s[i]
            if c.isnumeric():
                cur += c
            elif c != ' ':
                cur = int(cur)
                if stack and (stack[-1] == '*' or stack[-1] == '/'):
                    if stack[-1] == '*':
                        cur *= stack[-2]
                    else:
                        cur = stack[-2] // cur
                    stack.pop()
                    stack.pop()
                stack.append(cur)
                cur = ''
                if i < len(s):
                    stack.append(s[i])
                else:
                    res = stack[0]
                    for i in range(2, len(stack)):
                        if type(stack[i]) is int:
                            if stack[i - 1] == '+':
                                res += stack[i]
                            else:
                                res -= stack[i]
                    return res
```
