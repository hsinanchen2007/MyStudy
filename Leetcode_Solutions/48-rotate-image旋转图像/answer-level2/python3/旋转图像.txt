
#旋转使用1个额外变量



class Solution:
    def rotate(self, matrix):
        """
        Do not return anything, modify matrix in-place instead.
        """
        # 从外圈到内圈旋转

        n_dim = len(matrix)  # 维度 n x n矩阵

        if n_dim <= 1:
            return  # do nothing

        def rotate_elems(x, y): # 一圈圈旋转矩阵
            n_elems = y - x
            for i in range(n_elems):
                tmp = matrix[x][x + i]
                matrix[x][x + i] = matrix[y - i][x]
                matrix[x + i][y], tmp = tmp, matrix[x + i][y]
                matrix[y][y - i], tmp = tmp, matrix[y][y - i]
                matrix[y - i][x] = tmp

        s, n = 0, n_dim - 1
        while n_dim > 0: # 从外圈旋转到内圈
            rotate_elems(s, n)
            s += 1
            n -= 1
            n_dim -= 2


