```
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # # 1
        # while '()' in s or '[]' in s or '{}' in s:
        #     s = s.replace('()', '').replace('[]', '').replace('{}', '')
        # return not s
        
        # 2
        mapping = {')':'(', ']':'[', '}':'{'}
        stack = []
        for c in s:
            if c in mapping:
                if not stack or mapping[c] != stack.pop():
                    return False
            else:
                stack.append(c)
        return not stack
```
有效的字符串满足以下条件：
每当遇到一个闭括号的时候，它的左边一定是对应的开括号。