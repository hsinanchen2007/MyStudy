```
class NumMatrix(object):

    def __init__(self, matrix):
        """
        :type matrix: List[List[int]]
        """
        if not matrix or not matrix[0]:
            return
        m = len(matrix)
        n = len(matrix[0])
        self.mat = [[0 for _ in range(n)] for _ in range(m)]
        self.bit = [[0 for _ in range(n+1)] for _ in range(m+1)]
        for i in range(m):
            for j in range(n):
                self.update(i,j,matrix[i][j])
        

    def update(self, row, col, val):
        """
        :type row: int
        :type col: int
        :type val: int
        :rtype: None
        """

        diff = val - self.mat[row][col]
        self.mat[row][col] = val
        i = row+1
        while i < len(self.bit):
            # 注意j的初始化顺序
            j = col+1
            while j < len(self.bit[0]):
                self.bit[i][j] += diff
                j += j&(-j)
            i += i&(-i)
        #print self.mat
    
            
    def getSum(self,row,col):
        res = 0
        i = row
        while i > 0:
            # 注意j的初始化顺序
            j = col
            while j > 0:
                res += self.bit[i][j]
                j -= j&-j
            i -= i&-i
        return res

    def sumRegion(self, row1, col1, row2, col2):
        """
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        return self.getSum(row2+1, col2+1)-self.getSum(row1, col2+1)-self.getSum(row2+1, col1)+self.getSum(row1, col1)
        


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# obj.update(row,col,val)
# param_2 = obj.sumRegion(row1,col1,row2,col2)
```
具体思路请参考链接：[leetcode303.区域和检索 - 数组不可变、leetcode307.区域和检索 - 数组可修改、lc304.二维区域和检索 - 矩阵不可变、lc308.二维区域和检索 - 可变](https://blog.csdn.net/qq_28468707/article/details/103748050)