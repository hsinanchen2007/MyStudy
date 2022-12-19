### 解题思路
2*9 是9个2相加. 如果换成9*2, 递归次数就少很多了.

### 代码

```python3
class Solution:
    def _multiply(self, A: int, B: int) -> int:
        if B == 0:
            return 0
        elif B == 1:
            return A
        else:
            return A + self._multiply(A, B-1)

    def multiply(self, A: int, B: int) -> int:
        if A < 0 and B < 0:
            A, B = abs(A), abs(B)
        if A < B:
            A, B = B, A
        if B < 0:
            return 0 - self._multiply(A, B)
        else:
            return self._multiply(A, B)
```