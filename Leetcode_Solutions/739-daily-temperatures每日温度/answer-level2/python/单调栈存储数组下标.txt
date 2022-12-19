### 解题思路
栈存储数组下标

### 代码

```python3
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        stack = []
        res = [0 for i in range(len(T))]
        stack.append(0)
        for i in range(1,len(T)):
            while stack and T[i] > T[stack[-1]]:
                res[stack[-1]] = i-stack[-1]
                stack.pop()
            stack.append(i)
        return res
```