```python
class Solution:
    def isValid(self, s: str):
        stack = []
        m = {"(": ")", "{": "}", "[": "]"}
        
        for c in s:
            if c in m.keys():        # 如果是python2，keys()方法提取到for循环之外
                stack.append(c)
            elif c in m.values():    # 如果是python2，values()方法提取到for循环之外
                if len(stack) == 0:
                    return False
                
                last = stack.pop()
                if m[last] != c:
                    return False
                
        return len(stack) == 0
```