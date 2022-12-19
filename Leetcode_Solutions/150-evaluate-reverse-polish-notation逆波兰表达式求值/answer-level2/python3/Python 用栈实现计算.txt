### 解题思路
注意点：
负数除法取整是向负无穷方向取整，所以要用int(a/b)
isdigit智能判断正整数，无法判断小数和负数，要用isinstance()


### 代码

```python3
class Solution:
    def evalRPN(self, tokens) -> int:
        stack = []
        length = len(tokens)
        if length == 0:
            return 0
        for i in range(length):
            try:
                isinstance(int(tokens[i]),int)
                stack.append(int(tokens[i]))
            except:
                b = stack.pop()
                a = stack.pop()
                if tokens[i] == '+':
                    c = a+b
                    stack.append(c)
                if tokens[i] == '-':
                    c = a-b
                    stack.append(c)
                if tokens[i] == '/':
                    c = int(a/b)
                    stack.append(c)
                if tokens[i] == '*':
                    c = a*b
                    stack.append(c)
        return stack.pop()


```