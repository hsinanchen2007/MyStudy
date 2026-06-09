![2019-12-01 17-11-14 的屏幕截图.png](https://pic.leetcode-cn.com/c77623bb7592b24988c423cce12cca24f581e405d1442530d6bbb25d5bab00e4-2019-12-01%2017-11-14%20%E7%9A%84%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)
```python
    class Solution(object):
        def __init__(self):
            self.res = []

        def countSquares(self, matrix):
            """
            :type matrix: List[List[int]]
            :rtype: int
            """
            size = [len(matrix),len(matrix[0])]
            for r in range(size[0]):
                for c in range(size[1]):
                    num = self.findSquares(matrix,size,r,c)
                    self.res.append(num)
            print(self.res)
            return(sum(self.res))

        def findSquares(self, matrix, size, r, c):
            if not self.isValidIndex(size, r, c) or matrix[r][c] != 1 :
                return 0
            right = self.findSquares(matrix, size, r, c+1)
            if right == 0:
                return 1
            down = self.findSquares(matrix, size, r+1, c)
            if down == 0:
                return 1
            dia = self.findSquares(matrix, size, r+1, c+1)
            if dia == 0:
                return 1
            return min([right,down,dia]) + 1
            
        def isValidIndex(self, size, r, c):
            return r < size[0] and c < size[1]

![2019-12-01 19-10-08 的屏幕截图.png](https://pic.leetcode-cn.com/d7ef069b639bee4ee578aa2f9f6e381e2af2bc0fc2cffa7dbafcbb4a92ce9122-2019-12-01%2019-10-08%20%E7%9A%84%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)


    class Solution(object):
        def countSquares(self, matrix):
            """
            :type matrix: List[List[int]]
            :rtype: int
            """
            row = len(matrix)
            col = len(matrix[0])
            res = 0
            for r in range(0,row):
                for c in range(0,col):
                    if r == 0 or c == 0:
                        res += matrix[r][c]
                        continue
                    if matrix[r][c] == 1:
                        matrix[r][c] = min([matrix[r][c-1],matrix[r-1][c],matrix[r-1][c-1]]) + 1
                        res += matrix[r][c]
            # res = 0
            # for r in matrix:
            #     for c in r:
            #         res += c
            return res 


