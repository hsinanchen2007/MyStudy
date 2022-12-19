### 解题思路
首先考虑两种特殊的情况，列数或行数为0的情况，此时应该返回false。
接下来按行寻找target所在的行，遍历找到第一个行序数最大的且行中第一个元素大于等于target的行，这行就是target的可能所在行。
再用二分法寻找target是否在第i+1行中。

### 代码

```python
class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        
        if len(matrix) == 0:
            return False
        elif len(matrix[0]) == 0:
            return False
            
        i = 0
        while i < len(matrix) and target >= matrix[i][0] :
            i += 1
        i -= 1

        if matrix[i][0] == target:
            return True
        left = 0
        right = len(matrix[0]) - 1
        while left <= right:
            pivot = int((left + right + 1) // 2)
            if matrix[i][pivot] == target:
                return True
            elif right == pivot :
                break
            elif matrix[i][pivot] > target:
                right = pivot
            else:
                left = pivot
        return False
        

```