### 解题思路
选好起始位置左下角，当目标值比初始值小时，i上移减一，目标值比初始值大时右移。从此循环下去：循环条件i要大于等于零，j小于列的元素个数。

### 代码

```python3
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
            if target>matrix[i][j]:
                j+=1
            else:
                i-=1        
        return False
```