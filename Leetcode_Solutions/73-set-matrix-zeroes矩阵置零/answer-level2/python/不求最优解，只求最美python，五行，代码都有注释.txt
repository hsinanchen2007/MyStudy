时间复杂度击败97%， 空间复杂度击败38%，作者：lebhoryi@gmail.com
```python
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # 获取每一行，假如有0 就整行置为0
        row = [[0] * len(i) if 0 in i else i for i in matrix]
        # 获取每一列，假如有0 就整列置为0
        col = [[0] * len(j) if 0 in j else list(j) for j in zip(*matrix)]
        # 将列排序转换为行排序
        # zip(*col) 不能直接通过zip(*col)[1]取值，且返回的每个元素是元组
        # 下面做了两步转换，先将zip()返回的各个元组转换为列表，在将整个转换为list
        col2row = list(map(list, zip(*col)))
        for i in range(len(matrix)):
            # 替换matrix各行
            # matrix[i] = col2row[i]
            # # 如果一整行为0， 则替换为0
            # if row[i] == [0] * len(matrix[0]):
            #     matrix[i] = row[i]
            matrix[i] = col2row[i] if row[i] != [0] * len(matrix[0]) else row[i]
```
