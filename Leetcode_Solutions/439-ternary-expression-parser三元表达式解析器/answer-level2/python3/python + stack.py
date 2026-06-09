```python
class Solution:
    def parseTernary(self, expression: str) -> str:
        stack = []
        for e in reversed(expression):
            if stack == [] or e.isdigit() or e == '?':
                stack.append(e)
            elif  e == 'T' or e == 'F':
                if stack[-1] != '?': stack.append(e)
                else:
                    stack.pop() # pop ?
                    a = stack.pop()
                    b = stack.pop()
                    stack.append(a if e == 'T' else b)
        return stack[-1]
```