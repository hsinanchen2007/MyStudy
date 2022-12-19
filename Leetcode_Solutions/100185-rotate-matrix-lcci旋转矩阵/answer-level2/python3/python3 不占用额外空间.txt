### 解题思路
既然不占用额外空间，那么肯定就不能直接旋转了，需要牺牲一些时间复杂度
观察发现，整个矩阵旋转的过程可以由每一圈数字旋转来得到。比如N=3，那么矩阵顺时针旋转90度就相当于最外圈的数字旋转了90度，也就是各个数字依次往后面移动了一位。
N = 4，就相当于最外圈的数字顺时针移动了两次，内圈的数字宽度比较小，移动了1次，因此我们在原矩阵的基础上一圈一圈的移动即可，可以不占用额外的存储空间


### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        #思路：既然不采用额外空间，那我就移动来解决，旋转相当于每一圈数字的转动
        N = len(matrix)
        if matrix == []:
            return []
        if  N == 1:
            return matrix
        def tansfer(start):
            #转动函数
            end = N - start -1
            #开始转动
            for i in range(start+1,end+1):
                #上
                temp = matrix[start][start]
                matrix[start][start] = matrix[start][i]
                matrix[start][i] = temp
            for i in range(start+1,end+1):
                #右
                temp = matrix[start][start]
                matrix[start][start] = matrix[i][end]
                matrix[i][end] = temp
            for i in range(end-1,start-1,-1):
                #下
                temp = matrix[start][start]
                matrix[start][start] = matrix[end][i]
                matrix[end][i] = temp
            for i in range(end-1,start,-1):
                #左
                temp = matrix[start][start]
                matrix[start][start] = matrix[i][start]
                matrix[i][start] = temp
        
        start = 0
        length = N - 2 * start
        while length >= 1:
            for _ in range(length-1):
                tansfer(start)
            start += 1
            length = N - 2 * start
        


            
```