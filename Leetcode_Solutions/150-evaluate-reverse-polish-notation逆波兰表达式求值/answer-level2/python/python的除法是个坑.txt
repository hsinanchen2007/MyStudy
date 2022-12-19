那就重写除法

```python
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            if token not in "+-*/":
                stack.append(token)
            else:
                num2 = int(stack.pop())
                num1 = int(stack.pop())
                if token == "+":
                    stack.append(num1+num2)
                elif token == "-":
                    stack.append(num1-num2)
                elif token == "*":
                    stack.append(num1*num2)
                else:
                    stack.append(self.div(num1,num2))
                # print(stack[-1])
        # print(stack)
        return stack.pop()
    def div(self,num1,num2):
        sgn = 1
        if num1 < 0:
            num1 = -num1
            sgn *= -1
        if num2 < 0:
            num2 = -num2
            sgn *= -1
        return sgn*(num1//num2)
```