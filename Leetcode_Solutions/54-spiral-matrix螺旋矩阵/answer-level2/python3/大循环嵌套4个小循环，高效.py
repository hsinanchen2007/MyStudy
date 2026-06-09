思路就是1个大循环内部套4个小循环，每一个小循环打印的坐标想清楚即可。
```
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if matrix == []:
            return []
        
        row = len(matrix)
        column = len(matrix[0])  
        
        ans = []
        tmp_row = row
        tmp_column = column
        out_loop = (min(row, column) + 1) // 2
        
        for i in range(out_loop):
            if tmp_row == 0 or tmp_column == 0:
                break
            if tmp_row == 1:
                for j in range(tmp_column):
                    ans.append(matrix[i][i + j])
                break
            if tmp_column == 1:
                for j in range(tmp_row):
                    ans.append(matrix[i + j][i])
                break
            
            for j in range(tmp_column - 1):
                ans.append(matrix[i][i + j])
            
            for j in range(tmp_row - 1):
                ans.append(matrix[i + j][column - 1 - i])
            
            for j in range(tmp_column - 1):
                ans.append(matrix[row - 1 - i][column - 1 - i - j])
            
            for j in range(tmp_row - 1):
                ans.append(matrix[row - 1 - i - j][i])
            
            tmp_row -= 2
            tmp_column -= 2
        
        return ans
```
执行用时:
36 ms,在所有 Python3 提交中击败了98.77%的用户
内存消耗:
13.9 MB,在所有 Python3 提交中击败了5.66%的用户