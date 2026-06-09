### 解法1：
利用栈后进先出的特性：
```python []
class Solution(object):
    def isValid(self, s):
        stack = []
        judge = {'()','[]','{}'}
        for i in s:
            if not stack: 
                stack.append(i)
            else:
                if stack[-1]+i in judge:
                    stack.pop()
                else:
                    stack.append(i)
                    
        return stack == []
```
