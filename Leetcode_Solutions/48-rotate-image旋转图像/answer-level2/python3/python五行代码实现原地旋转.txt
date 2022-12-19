python3

五行代码原地实现原地旋转：转置和水平翻转两个步骤。

```
class Solution:
    def rotate(self, matrix) -> None:

        for i in range(len(matrix)):
            for j in range(i, len(matrix[0])):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        for row in matrix:
            row.reverse()
```