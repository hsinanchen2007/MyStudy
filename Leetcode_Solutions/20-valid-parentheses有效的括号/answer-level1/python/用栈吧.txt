```
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        my_map = {
            ')': '(',
            ']': '[',
            '}': '{',
        }
        for i in s:
            if i in ('(', '[', '{'):
                stack.append(i)
            elif i in (')', ']', '}'):
                if not stack:
                    return False
                if stack.pop() != my_map[i]:
                    return False
        if stack:
            return False
        return True
```
