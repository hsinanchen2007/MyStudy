```
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for t in tokens:
            if t in ['+', '-', '*', '/']:
                a = stack.pop()
                b = stack.pop()
                if t == '+': 
                    tmp = b + a
                elif t == '-': 
                    tmp = b - a
                elif t == '*': 
                    tmp = b * a 
                elif t == '/': 
                    tmp = int(b / a)
                stack.append(tmp)
            else:
                stack.append(int(t))
        return stack.pop()
```
