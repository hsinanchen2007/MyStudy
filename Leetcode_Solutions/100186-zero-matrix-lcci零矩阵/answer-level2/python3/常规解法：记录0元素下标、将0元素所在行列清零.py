### 解题思路
此题有个误区就是使用嵌套循环，遍历数组然后遇到零元素就将所在行列清零，
这么做得到的只能是元素全为0的矩阵。

容易想到的解法是**记录零元素的下标**，然后将所在下标的行列清零。

>执行用时 :44 ms     (91.72%)
>内存消耗 :13.7 MB    (100.00%)
### 代码

```python3
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        coordinates = []
        for i, item in enumerate(matrix):
            for j, enum in enumerate(item):
                if enum == 0:
                    coordinates.append((i, j))
        col_len = len(matrix[0])
        raw_len = len(matrix)
        for cord in coordinates:
            # 将行清零
            for j in range(col_len):
                matrix[cord[0]][j] = 0
            # 将列清零
            for i in range(raw_len):
                matrix[i][cord[1]] = 0
```