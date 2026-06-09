```python3
## 用两个栈分别存储无效的括号对应的index.
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stack1 = []
        stack2 = []
        for i in range(len(s)):
            if s[i] == '(':
                stack1.append(i)
            elif s[i] == ')' and stack1:
                stack1.pop()
            elif s[i] == ')':
                stack2.append(i)
            else:
                continue
        stack1.extend(stack2)
        res = ""
        for i in range(len(s)):
            if i in stack1:
                continue
            res += s[i]
        return res

