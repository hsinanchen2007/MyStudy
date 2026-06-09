```python
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        if T == []: return []
        res = [0] * len(T)
        stack = []
        for index, t in enumerate(T):
            while stack and t > stack[-1][0]:
                top, topIndex = stack.pop()
                res[topIndex] = index - topIndex
            stack.append((t, index))
        return res
```