### 解题思路
Traversing a string; Unpackagede stack struction;

### 代码

```python
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        flag = True
        stack = []
        for char in s:
            if char == '{' or char == '[' or char == '(':
                stack.append(char)
                continue
            elif len(stack)==0:
                flag = False
                break
            elif (stack[-1] == '{' and char == '}') or (stack[-1] == '[' and char == ']' or stack[-1] == '(' and char == ')'):
                stack.pop()
                continue
            else:
                flag = False
        if len(stack) == 0:
            return flag
        else:
            return False
```