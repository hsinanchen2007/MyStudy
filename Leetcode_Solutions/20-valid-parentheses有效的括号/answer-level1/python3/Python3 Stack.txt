### 解题思路
用时击败99.92%
内存击败99.66%

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        left = ['(','[','{']
        # right = [')',']','}']
        for i in range(len(s)):
            if s[i] in left:
                stack.append(s[i])
            elif len(stack) != 0:
                temp = stack.pop()
                if s[i]==')' and temp != '(':
                    return False
                if s[i]==']' and temp != '[':
                    return False
                if s[i]=='}' and temp != '{':
                    return False  
            else:
                return False

        if len(stack) == 0:
            return True
        else:
            return False

```