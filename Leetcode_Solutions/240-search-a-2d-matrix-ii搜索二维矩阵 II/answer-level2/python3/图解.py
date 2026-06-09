### 解题思路
首先每行的元素从左到右升序排列，每列的元素从上到下升序排列，则从每一行最后一个元素开始查找，
若当前行最后的一个元素大于target，则查询向左移动，即列数减少一，若当前行的最后一个值小于target，则行数向下增加，即行数加一。
![...%B4%E7%9F%A9%E9%.MP4](57c4daee-7a41-4269-b768-7c93c878d190)
### 代码

```python3
class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        n = len(matrix)
        if n == 0:
            return False
        m = len(matrix[0])
        if m == 0:
            return False
        i = 0
        j = m -1
        while i < n and j >=0:
            if matrix[i][j]>target:
                j = j-1
            elif matrix[i][j]<target:
                i = i+1
            else:
                return True
        return False
```