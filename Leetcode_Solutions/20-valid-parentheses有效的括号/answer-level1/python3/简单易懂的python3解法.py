```
class Solution:
    def isValid(self, s: str) -> bool:
        
        dict = {'{':'}', '[':']', '(':')'}
        
        stack = []
        for ch in s:
            if ch in dict:
                stack.append(ch)
            else:
                if len(stack) == 0:
                    return False

                if dict[stack.pop()] is not ch:
                    return False 
        
        if len(stack) is not 0:
            return False
        return True
```

时间复杂度：O(n)
