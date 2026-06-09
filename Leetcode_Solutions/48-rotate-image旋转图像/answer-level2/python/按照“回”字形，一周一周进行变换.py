将n*n的矩阵按照“回”字形，一周一周的进行旋转变换。
重点是计算出每次变换元素之间的关系。
假设第m周，坐上角的坐标为`(top, left)`，右下角的坐标为`(bottom, right)`，则对于`i in range(right-left)`，坐标之间的变换关系为：
`matrix[top][left + i] ----> matrix[top + i][right] `
`matrix[top + i][right] ----> matrix[bottom][right - i]`
`matrix[bottom][right - i] ----> matrix[bottom - i][left] `
`matrix[bottom - i][left] ----> matrix[top][left + i] `
由于变换过程是覆盖关系，使用一个临时变量`temp`存储中间值。
```
class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        if not matrix:
            return []
        
        left, right, top, bottom = 0, len(matrix[0])-1, 0, len(matrix)-1
        
        while left <= right and top <= bottom
            for i in range(0, right-left):
                temp = matrix[top][left+i]
                matrix[top][left + i] = matrix[bottom - i][left]
                matrix[bottom - i][left] = matrix[bottom][right - i]
                matrix[bottom][right - i] = matrix[top + i][right]
                matrix[top + i][right] = temp
            
            left += 1
            right -= 1
            top += 1
            bottom -= 1
            
        return matrix
```