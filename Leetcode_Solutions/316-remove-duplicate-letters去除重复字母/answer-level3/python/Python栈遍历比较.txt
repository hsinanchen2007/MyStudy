### 解题思路
见注释

### 代码

```python3
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        stack = ['0']  # 放一个比字母都小的字符
        # 遍历字符串，，若不在，
        for i, c in enumerate(s):
            # 看元素在不在栈里，若不在
            if c not in stack:
                # 从栈顶元素开始比较，如果比栈顶元素小且s中还会再出现栈顶元素，则弹出栈顶元素
                while c < stack[-1] and stack[-1] in s[i + 1:]:
                    stack.pop()
                # 压入新元素
                stack.append(c)
        return ''.join(stack[1:])
```