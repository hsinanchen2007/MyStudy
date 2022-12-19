### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        stack = []
        res = [0]*len(T)
        for day in range(len(T)):
            while stack and T[stack[-1]] < T[day]:
                tmp = stack.pop()
                res[tmp] = day - tmp
            stack.append(day)
        return res
```