官方最优方案思路写的python版。核心就是利用好每行和每列都排序了。选择一个合适的起点，然后更具比对结果移动。

```
class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        i=len(matrix)-1
        j=0
        
        while i>=0 and j<len(matrix[0]):
            if target==matrix[i][j]:
                return True
            elif target>matrix[i][j]:
                j+=1
            else:
                i-=1
        return False
```
