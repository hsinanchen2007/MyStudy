思路：
1、取第一行最后一个数，作为第一个数，统计矩阵中小于等于这个数的的个数k1，以及矩阵中与这个数相等的数的个数，并减1得到k2
2、如果k小于等于k1并且大于等于k1-k2，返回其位置（x,y）
3、如果k1小于k，x = x + 1,继续执行第二步
4、如果k1大于k，y = y + 1,继续执行第二步
# class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        n = len(matrix)
        x = 0
        y = n - 1
        while x < n and y >= 0:
            c, c1 = self.count_aim(matrix, matrix[x][y], n)
            if k >= c-c1 and k <= c:
                return matrix[x][y]
            elif c < k:
                x = x + 1
            else:
                y = y - 1

    def count_aim(self, matrix, aim, n):
        count1 = 0
        count2 = 0
        for i in range(n):
            j = n - 1
            l = 0
            while j >= 0 and matrix[i][j] > aim:
                if matrix[i][j] > aim:
                    j = j - 1
            h = n-1
            while h >= 0 and matrix[i][h] >= aim:
                if matrix[i][h] == aim:
                    l = l + 1
                h = h - 1

            count1 = count1 + j + 1
            count2 = count2 + l
        return count1, count2-1
