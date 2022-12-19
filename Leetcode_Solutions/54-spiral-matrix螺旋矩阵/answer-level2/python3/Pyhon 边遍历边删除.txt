```
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        while matrix:
            res.extend(matrix.pop(0))  # 删除矩阵第一行并添加
            if matrix and matrix[0]:
                for row in matrix:  
                    res.append(row.pop())  # 删除矩阵每一行的末尾元素并添加
            if matrix:
                res.extend(matrix.pop()[::-1])  # 删除矩阵最后一行并倒序添加
            if matrix and matrix[0]:
                for row in matrix[::-1]:
                    res.append(row.pop(0))  # 删除矩阵每一行的第一个元素并添加
        return res
```
