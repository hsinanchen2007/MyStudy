class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        """
        遍历上行,右列,下行,左列,但是会出现矩阵的角重复计算的时候,观察发现:
        4个角的重复算入只发生在一行或者一列的时候,故一行一列的情况单独处理即可
        
        """
        def circle(start, m, n):
            if m <= 0 or n <= 0:
                return
            nonlocal res
            if m == 1:  # 一行的情况
                res += [matrix[start[0]][start[1] + i] for i in range(n)]  # 上行
                return
            if n == 1:  # 一列的情况
                res += [
                    matrix[start[0] + i][start[1] + n - 1] for i in range(m)
                ]  # 右列
                return
            # 多行多列的情况
            res += [matrix[start[0]][start[1] + i] for i in range(n)]  # 上行
            res += [
                matrix[start[0] + i][start[1] + n - 1] for i in range(1, m)
            ]  # 右列
            res += [
                matrix[start[0] + m - 1][start[1] + n - 1 - i]
                for i in range(1, n)
            ]  # 下行
            res += [
                matrix[start[0] + m - 1 - i][start[1]]
                for i in range(1, m - 1)
            ]  # 左列

            newStar = [start[0] + 1, start[1] + 1]
            newM = m - 2
            newN = n - 2

            return circle(newStar, newM, newN)

        res = list()
        if not matrix:
            return []
        m, n = len(matrix), len(matrix[0])
        start = [0, 0]
        circle(start, m, n)
        return res