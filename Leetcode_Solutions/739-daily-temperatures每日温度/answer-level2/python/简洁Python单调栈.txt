### 解题思路
单调栈
for 循环要从后往前扫描

### 代码

```python3
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        ans = [None] * len(T)
        stack = []
        for i in range(len(T) - 1, -1, -1):
            while stack and T[stack[-1]] <= T[i]:
                stack.pop()
            if stack:
                ans[i] = stack[-1] - i
            else:
                ans[i] = 0
            stack.append(i)
        return ans
```