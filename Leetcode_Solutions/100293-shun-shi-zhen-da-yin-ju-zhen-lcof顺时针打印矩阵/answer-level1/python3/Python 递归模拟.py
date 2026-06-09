尝试用递归模拟迭代过程，速度稍慢，但是可接受

```python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        self._result = list()
        self._find(matrix, 0)

        return self._result
    
    def _find(self, matrix, direction):
        if not matrix or not matrix[0]:
            return self._result

        if direction == 0:  # 上
            self._result.extend(matrix[0])
            return self._find(matrix[1:], 1)

        if direction == 1:  # 右
            for row in matrix:
                self._result.append(row.pop())
            return self._find(matrix, 2)

        if direction == 2:  # 下
            self._result.extend(reversed(matrix[-1]))
            return self._find(matrix[:len(matrix) - 1], 3)

        if direction == 3:  # 左
            for row in reversed(matrix):
                self._result.append(row.pop(0))
            return self._find(matrix, 0)
```