![30通过.png](https://pic.leetcode-cn.com/bf1bbed3f5cbec42d8e07f1f5273c6e278267965984cb4c91a93c33bad3f8834-30%E9%80%9A%E8%BF%87.png)



解题思路：观察示例，发现结果可以通过对原列表翻转（reverse）后形成的矩阵再进行转置得到
代码：

    class Solution:
        def rotate(self, matrix: List[List[int]]) -> None:
            """
            Do not return anything, modify matrix in-place instead.
            """
            matrix.reverse()
            i = 0
            while i < len(matrix):
                j = i
                while j < len(matrix[i]):
                    temp = matrix[i][j]
                    matrix[i][j] = matrix[j][i]
                    matrix[j][i] = temp
                    # print('matrix = ', end='')
                    # print(matrix)
                    j += 1
                i += 1