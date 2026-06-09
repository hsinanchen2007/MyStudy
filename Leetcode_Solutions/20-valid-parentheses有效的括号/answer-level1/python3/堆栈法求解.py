左符号： '(', '[', '{'
右符号： ')', ']', '}'
用堆栈stack进行符号匹配
1. 遍历输入字符串，
    1.1 当输入左符号，入栈
    1.2 当输入右符号，如果堆栈不空，pop出栈顶符号，如果与右符号不配对则返回False; 
        如果堆栈为空，则返回False
2. 遍历结束后如果stack为空，则说明所有左右符号均匹配，放回True


```
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for sign in s:
            if sign in ['(', '[', '{']:
                stack.append(sign)
            elif len(stack) == 0:
                return False
            elif sign == ')' and stack[-1] == '(':
                stack = stack[:-1]
            elif sign == ']' and stack[-1] == '[':
                stack = stack[:-1]
            elif sign == '}' and stack[-1] == '{':
                stack = stack[:-1]
            else:
                return False
        if len(stack) == 0:
            return True
        return False
```
