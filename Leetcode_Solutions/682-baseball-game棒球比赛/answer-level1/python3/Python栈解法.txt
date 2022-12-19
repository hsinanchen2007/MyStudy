
```python []

class Solution:
    def calPoints(self, ops: List[str]) -> int:
        stack=[]
        sums=0
        for i in ops:
            if i!='C'and i!='D'and i!='+':
                stack.append(int(i))
            if i=='C':
                stack.pop()
            elif i=='D':
                stack.append(stack[-1]*2)
            elif i=='+':
                stack.append(stack[-1]+stack[-2])
        sums=sum(stack)
        return sums
```
