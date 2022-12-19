```python
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        stack = [0]
        res = [0] * len(T)
        for i in range(len(T)):
            while stack and T[i] > T[stack[-1]]:
                index = stack.pop()
                res[index] = i - index
            stack.append(i)
        return res
```