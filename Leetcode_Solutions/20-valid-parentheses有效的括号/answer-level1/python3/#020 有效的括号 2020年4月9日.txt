### 解题思路
1.用栈实现,左括号入栈，输入右括号时，成对的括号就弹出，不成对或此时为空栈则直接报错
2.将直接成对的括号剔除
### 代码

```python3
class Solution:
    def isValid(self, s):
        # 用栈实现,左括号入栈，输入右括号时，成对的括号就弹出，不成对或此时为空栈则直接报错
        dict1 = {'(':')', '[':']', '{':'}', '?':'?'}
        stack = ['?']
        if not s:
            return True
        for i in s:
            if i in dict1:
                stack += [i]
            elif i != dict1[stack.pop()]:
                return False
        return len(stack)==1


        # 将直接成对的括号剔除
        """
        while '{}' in s or '[]' in s or '()' in s:
            s = s.replace('{}', '')
            s = s.replace('[]', '')
            s = s.replace('()', '')
        return s == ''
        """
```