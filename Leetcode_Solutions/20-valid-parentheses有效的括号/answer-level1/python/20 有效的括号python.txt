### 解题思路
        stack = []
        lookup = {
            "(":")",
            "[":"]",
            "{":"}"
        }
return True if not stack else False


### 代码

```python
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        lookup = {
            "(":")",
            "[":"]",
            "{":"}"
        }

        len_s = len(s)
        for i in range(len_s):
            if s[i] in lookup:
                stack.append(s[i])
                continue
            if stack and lookup[stack[-1]]==s[i]:
                stack.pop()
            else:
                return False

        return True if not stack else False
```