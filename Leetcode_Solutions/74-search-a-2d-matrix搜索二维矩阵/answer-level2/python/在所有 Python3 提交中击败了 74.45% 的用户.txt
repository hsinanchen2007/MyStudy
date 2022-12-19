### 解题思路
此处撰写解题思
因为这个数组排列的太过规律，所以可以先确定下行，然后再对该行进行列查找即可
时间= log(行数) + log(列数)
虽然代码的简洁和优雅性不如将整个表格看成一个列表
但是时间上理论要快
### 代码

```python3
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or len(matrix) == 0  or len(matrix[0]) == 0:
            return False
        rows, cols = len(matrix) , len(matrix[0])
        if target < matrix[0][0]  or target > matrix[rows-1][cols-1]:
            return  False
        row = 0
        if target >= matrix[rows-1][0]:
            row = rows-1
        else:
            up,bottom = 0,rows-2
            while up <= bottom:
                row = up + (bottom - up) //2
                if matrix[row][0] == target:
                    break
                elif matrix[row][0] > target:
                    bottom = row -1
                else:
                    up =row +1
            if up > bottom:
                row = bottom
        left, right = 0, cols-1
        while left <= right:
            mid = left + (right - left) // 2
            if matrix[row][mid]  == target:
                return True
            elif matrix[row][mid] > target:
                right = mid -1
            else:
                left = mid +1
        return False
```