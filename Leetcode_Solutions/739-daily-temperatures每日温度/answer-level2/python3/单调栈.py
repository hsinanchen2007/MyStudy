维护一个单调递减栈即可

```python
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        stack = []
        n = len(T)
        res = [0]*n
        for i in range(n):
            curr = T[i]
            # stack.append(T[i])
            while stack and stack[-1][1] < T[i]:
                j, temp = stack.pop()
                res[j] = i - j
            stack.append([i, curr])
        return res
```