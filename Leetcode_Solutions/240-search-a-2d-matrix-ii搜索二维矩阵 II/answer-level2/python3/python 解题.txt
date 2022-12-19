执行用时 : 40 ms, 在Search a 2D Matrix II的Python提交中击败了100.00% 的用户
内存消耗 : 15.7 MB, 在Search a 2D Matrix II的Python提交中击败了20.77% 的用户
```
class Solution(object):
    def searchMatrix(self, matrix, target):
        if matrix == []:
            return False
        m,n = len(matrix),len(matrix[0])
        i,j = m-1,0
        while( i >= 0 and j < n):
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] < target:
                j+=1
            elif matrix[i][j] > target:
                i-=1
        return False
```
从左下角，如果当前值比目标值小，则向右移动指针，如果当前值比目标值大，则向上移动指针

        