### 解题思路
不用多少，看代码就明白；主要是剩下最后一行或者一些时比较难处理

### 代码

```python3
class Solution:
    # def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
    def spiralOrder(self, matrix):
        if not matrix:
            return matrix
        re = []
        high = len(matrix)
        weigh = len(matrix[0])
        for _ in range(min(high, weigh)//2):
            re += matrix.pop(0)
            re += [i.pop() for i in matrix]
            re += matrix.pop()[::-1]
            re += [i.pop(0) for i in matrix][::-1]
        if not matrix or not matrix[0]:
            return re
        elif len(matrix[0]) > 1:
            return re + matrix[0]
        else: return re + [i.pop() for i in matrix]
```