### 解题思路
做过大量这一题目。
可以把先前做过的整理在这里。

官方解答给出了 6 种解法，过多。



### 代码

```python3
class Solution:
    def fib(self, N: int) -> int:
        if N == 0:
            return 0
        F0 = 0
        F1 = 1
        for _ in range(N-1):
            F2 = F1 + F0
            F0, F1 = F1, F2
        return F1
```