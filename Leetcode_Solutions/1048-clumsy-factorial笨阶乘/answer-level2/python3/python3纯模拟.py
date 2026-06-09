### 解题思路
纯模拟的，没有公式法快

### 代码

```python3
class Solution:
    def clumsy(self, N: int) -> int:
        stack = []
        res = N
        for i in range(1,N):
            if i % 4 == 0:
                res = N - i
            elif i % 4 == 1:
                res *= N - i
            elif i % 4 == 2:
                res //= N - i
                stack.append(res)
                res = N - i - 1
            elif i % 4 == 3:
                stack.append(res)
                res = N - i - 1
        stack.append(res)
        for i in range(1,len(stack)):
            if i % 2 == 0:
                stack[i] = -stack[i]
        return sum(stack)
```

贴一个公式法的代码吧，推导也很简单
```
class Solution:
    def clumsy(self, N: int) -> int:
        return (N + [1, 2, 2, -1][N % 4]) if N > 4 else [7, 1, 2, 6][N % 4]
```
