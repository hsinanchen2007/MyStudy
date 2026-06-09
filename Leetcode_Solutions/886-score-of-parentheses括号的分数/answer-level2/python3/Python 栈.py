```python
class Solution:
    def scoreOfParentheses(self, S: str) -> int:
        stack = []
        for s in S:
            if s == ')':
                tempSum = 0
                a = stack.pop()
                while a != '(':
                    tempSum += a
                    a = stack.pop()
                if tempSum == 0: stack.append(1)
                else: stack.append(2 * tempSum)
            else:
                stack.append(s)
        return sum(stack)

```