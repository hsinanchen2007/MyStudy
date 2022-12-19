### 解题思路

简单计算机想到stack
注意每次操作都是要保存结果的这样遇到“c”的时候能够cancel，pop（），
其他的都是append当前的计算结果，
并且只有“c”才会pop保持一致性

### 代码


```python3
class Solution:
    def calPoints(self, ops: List[str]) -> int:

        stack = []

        for i in ops:
            if i == '+':
                stack.append(stack[-1]+stack[-2])
            elif i == 'C':
                stack.pop()
            elif i == 'D':
                stack.append(stack[-1]*2)
            else:
                stack.append(int(i))
        
        return sum(i for i in stack)
```
```