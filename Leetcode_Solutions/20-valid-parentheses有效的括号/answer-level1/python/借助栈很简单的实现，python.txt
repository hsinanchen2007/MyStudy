借助栈很简单的实现。

 - 遍历字符串 
 - 如果遇到左括号，压栈。
 - 如果遇到右括号，若栈为空，则不匹配，返回`false`；若栈不为空，弹出栈顶元素，如果两个括号匹配，则继续遍历字符串，如果不匹配，返回`false`。
 - 字符串遍历结束后，若栈为空，则匹配，返回`true`；若栈不为空，说明不匹配，返回`false`。
```py
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        left = ['(', '{', '[']
        right = [')', '}', ']']
        match = {
            ')' : '(',
            '}': '{',
            ']': '['
        }
        for i in s:
            if not stack and (i in right):
                return False
            if stack and (i in right):
                temp = stack.pop()
                if match[i] == temp:
                    continue
                else:
                    return False
            if i in left:
                stack.append(i)
        if not stack:
            return True
        return False

```

 
