### 解题思路
类似")))))"永远记录最右侧")"的index,遍历字符串，当为”("入栈，为“)"出栈，记录res=max(res,index-stack[-1])

### 代码

```python3
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack=[-1]
        res=0
        for index,char in enumerate(s):
            if char=="(":
                stack.append(index)
            else:
                stack.pop()
                if not stack:
                    stack.append(index)
                else:
                    res=max(res,index-stack[-1])
        return res
```