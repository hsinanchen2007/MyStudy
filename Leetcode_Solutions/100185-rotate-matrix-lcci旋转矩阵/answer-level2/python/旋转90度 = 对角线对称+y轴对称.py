### 解题思路
明白旋转90度等效于先按照[0,0]-[3,3]这个对角线对称，再按照y轴对称就简单了

刚开始粗心犯了个错误，在对角线对称的时候，要按照i=[0~size) j=[i~size)的上三角阵轮询，我按照全部轮询，结果死活不对。

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        size = len(matrix)
        for i in range(size):
            for j in range(i,size):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        for i in range(size):
            matrix[i] = matrix[i][::-1]
        print(matrix)
```