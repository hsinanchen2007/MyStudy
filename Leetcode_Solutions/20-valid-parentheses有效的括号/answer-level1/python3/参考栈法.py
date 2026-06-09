```
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        d = {'(':')','[':']','{':'}'}
        if len(s) != 0:
            for a in s:
                if a in d: 
                    stack.append(a)
                else: 
                    if len(stack):
                        if a!= d[stack.pop()]:
                            return False
                    else: return False
            if len(stack)!= 0: 
                return False
            else:
                return True
        else:
            return True

```
