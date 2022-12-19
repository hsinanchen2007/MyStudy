### 解题思路
思路简单，有两个注意的地方：
1. count本来写到totalNQueens函数里，用global count在backtrack里声明但是会报错，这里暂时还没找到原因。所以写到__init__里用self.count了
2. isvalid函数里修改'.'为'Q'时尽量使用切片操作，代码更加简洁。也可以先转换成列表再join。

有知道第一点global报错原因的大佬请指教！

### 代码

```python
class Solution(object):

    def __init__(self):
        self.count = 0

    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        borad = [('.' * n) for x in range(n)]

        def backtrack(borad, row):
            #global count?
            if row == n:
                self.count += 1
                return
            for col in range(n):
                if isvalid(borad, row, col):
                    borad[row] = borad[row][:col] + 'Q' + borad[row][col+1:]
                    backtrack(borad, row+1)
                    borad[row] = borad[row][:col] + '.' + borad[row][col+1:]
        
        def isvalid(borad, row, col):
            #col
            for i in range(row):
                if borad[i][col] == 'Q':
                    return False
            #right up side
            a = row - 1
            b = col + 1
            while a >= 0 and b < n:
                if borad[a][b] == 'Q':
                    return False
                a -= 1
                b += 1
            #left up side
            x = row - 1
            y = col - 1
            while x >= 0 and y >= 0:
                if borad[x][y] == 'Q':
                    return False
                x -= 1
                y -= 1
            return True

        backtrack(borad, 0)
        return self.count


```