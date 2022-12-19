### 解题思路
使用一个与matrix大小相同的辅助数组，临时存储旋转后的结果。从最后一行从左到右逐行遍历matrix中的每一个元素，对应辅助数组的第一列从上到下，将元素存放到辅助数组中对应的位置。在遍历完成之后，再将辅助数组中的结果赋值到原数组中。


### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        tem = [[0 for i in range(n)] for j in range(n)]
        for i in range(n-1,-1,-1):
            for j in range(n):
                tem[j][n-1-i]=matrix[i][j]
        for i in range(n):
            for j in range(n):
                matrix[i][j]=tem[i][j]
```