![image.png](https://pic.leetcode-cn.com/47da8f37dcda4b70008d9ac55c5db8aa374cbe1b78100d96ef9ca4587b16c48e-image.png)
```
def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        #思路：先顺时针打印外圈，再构造该矩阵的内圈矩阵，递归顺时针打印内圈矩阵
        #行数
        rows = len(matrix)
        #列数
        if rows == 0:
            return []
        elif rows == 1:
            return matrix[0]            
        else:
            cols = len(matrix[0])
            #只有一列的情况,直接按列打印
            if cols == 1:
                return [matrix[i][0] for i in xrange(0,rows)]
        #求出矩阵最外圈的元素
        #先往右遍历
        out_layer = matrix[0]
        #再往下遍历
        for i in xrange(1,rows):
            out_layer.append(matrix[i][cols-1])
        #再往左遍历
        out_layer.extend(matrix[rows-1][cols-2::-1])
        #print "out_layer:",out_layer
        #再往上遍历
        for i in range(rows-2,0,-1):
            out_layer.append(matrix[i][0])
        #print "out_layer:",out_layer
        #再递归求矩阵的里圈矩阵
        #里圈矩阵是一个rows-2,cols-2的矩阵
        new_matrix = []
        if rows > 2 and cols > 2:
            for i in xrange(1,rows-1):
                new_matrix.append(matrix[i][1:-1])
        #print "new_matrix:",new_matrix
        out_layer.extend(self.spiralOrder(new_matrix))
        return out_layer

```

