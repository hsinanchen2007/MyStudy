### 解题思路
和官方解题思路相同但是简化了一下。

### 代码

```python3
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        next = [0] * len(T)
        stack = []
        for i in range(len(T)) :
            while stack != [] and T[i] > stack[-1][0] :
                next[stack[-1][1]] = i - stack[-1][1]
                stack.pop()
            stack.append([T[i], i])
        return next
```