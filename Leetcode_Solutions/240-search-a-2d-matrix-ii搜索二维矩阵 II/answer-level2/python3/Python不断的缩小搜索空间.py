### 解题思路
以矩阵的右上角作为起点，由于整个矩阵下一行的数比上一行的大，前一列的数比后一列的小。
所以我们如果发现目标值小于当前值就往左走，如果目标值大于当前值就往下走。
在走的过程中如果发现目标值就返回True，否则如果走出了矩阵的界限就表示矩阵中不存在目标值，返回False。

### 代码

```
class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False

        height = len(matrix)
        width = len(matrix[0])
        row = 0
        column = width-1
        
        while 0 <= column < width and 0 <= row < height:
            #选取右上角的数字为起点
            found = matrix[row][column]
            if target < found:
                #如果目标值比当前值小则往左走
                column -= 1
            elif target > found:
                #如果目标值比当前值大往下走
                row += 1
            else:#找到了目标值
                return True
        return False
            
```
