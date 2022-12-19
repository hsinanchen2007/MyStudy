### 解题思路
使用栈，遍历s：
1. 遇到除了数字和右括号之外的其他字符，都压入栈
2. 当遇到数字的时候，检查栈最后一个是不是也是数字，如果是的话就合并，不是的话，就把数字压栈
3. 如果遇到右括号，不断取出栈顶字符，直到左括号，取出左括号后，栈顶元素就是一个数字代表个数，此时用刚才取出的所有字符乘以这个个数，并把结果入栈
4. 最后，把栈中的字符串拼接起来。

### 代码

```python3
class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        for c in s:
            if c.isdigit():
                if stack and stack[-1].isdigit():
                    stack[-1] += c
                else:
                    stack.append(c)
            elif c == ']':
                rpt = ''
                while stack[-1] != '[':
                    rpt = stack.pop() + rpt
                stack.pop()
                stack.append(int(stack.pop())*rpt)
            else:
                stack.append(c)
        return ''.join(stack)
```