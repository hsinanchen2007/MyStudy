```python
import operator
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        ops = {'+': operator.add, '-': operator.sub, '*': operator.mul, '/': operator.truediv}
        s = []
        for x in tokens:
            if x not in ops:
                s.append(x)
            else:
                a = s.pop()
                b = s.pop()
                # 这里使用 truediv 处理类似 6 / -3 的情况
                s.append(int(ops[x](int(b), int(a))))
        return int(s[0])
```
