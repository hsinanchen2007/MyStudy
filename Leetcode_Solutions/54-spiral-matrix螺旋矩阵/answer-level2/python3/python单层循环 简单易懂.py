一层循环完事。用4个参数，分别是`StartX`,`endX`,`startY`和`endY`来控制，就像变量名一样很好理解，每一轮循环就是一圈（4行/列），分别是👉，👇，👈和👆。相应地，每打印一行就将相应的控制参数做自增或者自减。有一个小问题就是，例如遇到某一圈只有一个数字（比如3x3矩阵中间的那个数字）容易漏，注意将其归入某个指定的行/列来打印，同时防止重复：
```python
class Solution:
    def spiralOrder(self, matrix):
        if matrix is None or len(matrix) == 0 or len(matrix[0]) == 0 : return []
        lenX = len(matrix[0])
        lenY = len(matrix)
        startX = 0
        endX = lenX
        startY = 0
        endY = lenY
        l = []
        while (startX <= endX and startY <= endY):
            if (startY<endY):
                for i in range(startX,endX):
                    l.append(matrix[startY][i])
            startY+=1
            if (startX<endX):
                for i in range(startY,endY):
                    l.append(matrix[i][endX-1])
            endX-=1
            if (startY<endY):
                for i in range(startX,endX)[::-1]:
                    l.append(matrix[endY-1][i])
            endY-=1
            if (startX<endX):
                for i in range(startY,endY)[::-1]:
                    l.append(matrix[i][startX])
            startX+=1
        return l
```