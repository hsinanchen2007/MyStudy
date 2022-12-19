每次迭代pop掉最外圈数据并append/extend进answer，不断重复过程得出解。
如果每次拆掉边都判断一下是否结束会不够优雅，直接try掉解决。

```python
class Solution:
    def spiralOrder(self, matrix):
        answer = []
        try:
            while True:
                row = len(matrix)
                answer.extend(matrix.pop(0))
                for r in range(0, row - 1):
                    answer.append(matrix[r].pop(-1))
                answer.extend(matrix.pop(-1)[::-1])
                for r in range(row - 3, -1, -1):
                    answer.append(matrix[r].pop(0))
        except IndexError:
            pass

        return answer
```