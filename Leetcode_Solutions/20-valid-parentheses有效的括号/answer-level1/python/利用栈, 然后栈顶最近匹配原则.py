### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        """
        思路：利用栈, 然后栈顶最近匹配原则
        """
        if not s:
            return True
        if len(s) % 2 == 1: # 如果是匹配的，那么一定是偶数个字符
            return False
        stack = []
        mapping = {')':'(', '}':'{', ']':'['}
        for c in s:
            if c in mapping.values():
                stack.append(c)
            # 如果栈为空（说明进来的一定是右括号，肯定是无效的）或者栈顶元素和c不配对
            elif len(stack) == 0 or stack.pop() != mapping.get(c):
                return False
        return len(stack) == 0
```