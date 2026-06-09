### 解题思路
用栈的方法进行求解；stack=[]，遇到数放入stack中，遇见操作符，将stack最上面的两个操作数弹出，与操作符一起进行计算，并将求得的值放入stack中，继续求解，最后stack中存入的是最终的计算结果；

### 代码

```python3
class Solution:
    def evalRPN(self, tokens) -> int:
        if len(tokens) == 0:
            return 0
        operator = set(['+', '-', '*', '/'])

        stack = []
        for char in tokens:
            if char in operator:
                o1 = stack.pop()
                o2 = stack.pop()
                if char == '/':
                    o = eval('int(' + o2+char+o1 + ')')
                else:
                    o = eval(o2+char+o1)
                stack.append(str(o))
            else:
                stack.append(char)
        
        return int(stack[-1])
```