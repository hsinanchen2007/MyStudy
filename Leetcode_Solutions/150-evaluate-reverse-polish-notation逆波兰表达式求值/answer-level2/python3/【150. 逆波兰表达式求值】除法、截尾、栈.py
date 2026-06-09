### 解题思路
注释犯的错误: 1. 除法与整除 **2. 估计这么写有未定义行为**
另外题目要求取整数部分，不是整除，所以除法再截尾

### 代码

```python3
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for _ in tokens:
            if _ == "+":
                stack[-2] += stack[-1]
                stack.pop()
            elif _ == "-": 
                stack[-2] -= stack[-1]
                stack.pop()
            elif _ == "*":
                stack[-2] *= stack[-1]
                stack.pop()
            elif _ == "/":
                stack[-2] = int(stack[-2] / stack[-1])
                stack.pop()
                # stack[-1] //= stack.pop()
            else:
                stack.append(int(_))
        return stack[-1]
```