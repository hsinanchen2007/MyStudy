单调栈的思路是没错，但是呢，可以考虑在栈中添加索引信息，使得思路更加清晰！
```python
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        n = len(T)
        res = [0] * n
        # 单调栈
        stack = []
        for i in range(n-1, -1, -1):
            while stack and T[i] >= stack[-1][0]:
                stack.pop()
            res[i] = (stack[-1][1] - i) if stack else 0
            stack.append((T[i], i))
        return res

```