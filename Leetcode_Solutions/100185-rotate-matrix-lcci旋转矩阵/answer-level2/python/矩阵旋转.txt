    旋转矩阵这道题目也可以使用python的内置函数np.rot90(matrix, axes=(1, 0))完成，但是这样没有意义。
    经过分析我们可以发现：顺时针旋转90°的意义就是将矩阵的列元素变成行元素。这样的话我们可以逐个交换h矩阵的列元素和对应的行元素，但是这样还不行，我们发现矩阵的每行元素与最后的输出正好倒过来了，那么w最后再将矩阵的每行元素倒置即可实现矩阵的旋转。具体步骤如下：
    （1）逐个交换交换(i,j)与(j,i)位置上的元素
    （2）将矩阵的每一行元素倒置即可
代码如下：
class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        if not matrix:
            return
        m, n = len(matrix), len(matrix[0])
        for i in range(m-1):
            for j in range(i+1, n):
                # 交换(i,j)与(j,i)位置上的元素
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        # 将矩阵的每一行倒置
        for i in range(m):
            matrix[i][:] = matrix[i][::-1]