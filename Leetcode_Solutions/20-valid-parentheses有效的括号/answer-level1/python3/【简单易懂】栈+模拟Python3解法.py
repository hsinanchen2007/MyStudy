思路：辅助栈法！用列表模拟栈，用字典键值对模拟括号匹配。
- 特判：s为空时返回True
- 建立栈空间（列表stack）和括号匹配字典mapping
- 判断s中，若为左括号则进栈，若为右括号时栈为空或右括号与栈顶左括号不匹配，则返回False
- 遍历s结束后，若栈为空则返回True，栈不为空返回False

```
class Solution:
    def isValid(self, s: str) -> bool:
        if s is None or len(s) == 0:
            return True
        stack = []
        mapping = {')':'(', '}':'{', ']':'['}
        for char in s:
            if char=='(' or char=='{' or char=='[':
                stack.append(char)
            elif len(stack) == 0 or mapping[char] != stack.pop():
                return False
        return len(stack) == 0
```
