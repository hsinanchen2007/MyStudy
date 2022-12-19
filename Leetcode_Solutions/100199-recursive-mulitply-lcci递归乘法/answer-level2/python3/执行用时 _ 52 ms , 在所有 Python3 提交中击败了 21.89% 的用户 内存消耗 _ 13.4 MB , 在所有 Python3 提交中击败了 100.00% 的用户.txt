### 解题思路
1.判断哪个值更小
2.选择对应的函数进行递归，防止溢出

### 代码

```python3
class Solution:
    def multiply(self, A: int, B: int) -> int:
        def multiplyA(A: int, B: int) -> int:
            if A == 1:
                return B
            else:
                return B + multiplyA(A-1, B)        
        def multiplyB(A: int, B: int) -> int:
            if B == 1:
                return A
            else:
                return A + multiplyB(A, B-1)
        if A < B:
            return multiplyA(A, B)       
        else:
            return multiplyB(A, B)
```