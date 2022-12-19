


### 代码

```python3
class Solution:
    def calPoints(self, ops: List[str]) -> int:
        stack=[]
        for res in ops:
            if res== '+':
                stack.append(stack[-1]+stack[-2])
            elif res== 'D':
                stack.append(stack[-1]*2)
            elif res== 'C':
                stack.pop()
            else:
                stack.append(int(res))
        return sum(stack)
```