```
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        mapping = {')':'(',']':'[','}':'{'}

        for char in s:
            if char not in mapping: #凡左括号都压stack 
                stack.append(char)
            elif not stack or stack.pop() != mapping[char]: #遇到右括号时，若stack 已空 或不匹配则报错 e.g:]]
                #mapping[stack.pop()] 这种写法会错
                return False
            
        return not stack #stack 已空说明合法

```
