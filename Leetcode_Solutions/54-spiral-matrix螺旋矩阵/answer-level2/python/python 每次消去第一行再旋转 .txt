螺旋轨迹可以看作：每次取第一行（取完删掉），然后逆时针旋转90度，继续去第一行，直到全部消除
```
class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        
        if not matrix:
            return matrix
        res = []
        while matrix:
            #取第一行并消除
            res.extend(matrix[0])
            matrix.remove(matrix[0])

            tmp = []
            tmp2 = []
            if matrix:
                raw = len(matrix)
                col = len(matrix[0])
                #矩阵逆时针旋转90度
                for i in range(col):
                    for j in range(raw):
                        tmp.append(matrix[j][col - 1 - i])
                    tmp2.append(tmp)
                    tmp = []
                matrix = tmp2
        return res
```
