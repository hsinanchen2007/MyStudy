### 解题思路
此处撰写解题思路
matrix[::-1]实质是让 matrix上下翻转 而'='号前面写的是matrix[::]而非matrix是因为
前者实际上是在同一对象的不同位置复制元素，后者只是将名称矩阵与从矩阵切片构造的新对象链接。
最后zip(*)的可以理解为是zip()的相反，即理解为解压，返回压缩前的二维矩阵
### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        matrix[::] = zip(*matrix[::-1])
        # l = len(matrix)
        # for i in range(l):#左右翻转
        #     for j in range(l//2):
        #         matrix[i][j],matrix[i][l-j-1] = matrix[i][l-j-1],matrix[i][j]
        
        # for i in range(l):#对角线翻转
        #     for j in range(l-i):
        #         matrix[i][j],matrix[l-j-1][l-i-1] = matrix[l-j-1][l-i-1],matrix[i][j]
        
        # return
```