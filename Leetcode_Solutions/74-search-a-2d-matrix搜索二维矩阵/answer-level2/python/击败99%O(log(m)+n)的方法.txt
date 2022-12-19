### 解题思路
先定位查找元素的行信息，再定位列信息。

### 代码

```python3
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False
        len1,len2 = len(matrix),len(matrix[0])
        if target < matrix[0][0] or target > matrix[len1-1][len2-1]:
            return False
        row = self.findrow(target,matrix,len1)
        return self.findcolumn(target,matrix,row,len2)
    def findrow(self,target,matrix,len1):
        if len1 == 1:
            return 0
        for i in range(len1):
            if matrix[i][0] >= target:
                break
        if matrix[i][0] < target or matrix[i][0] == target:
            return i
        else:
            return i-1
    
    def findcolumn(self,target,matrix,row,len2):
        # for i in range(len2):
        #     if matrix[row][i] == target:
        #         return True
        # return False
        # 二分查找
        i,j = 0,len2-1
        while i<=j:
            mid = i + (j-i) // 2
            if matrix[row][mid] == target:
                return True
            elif matrix[row][mid] > target:
                j = mid - 1
            elif matrix[row][mid] < target:
                i = mid + 1
        return False

             

```