### 解题思路
此处撰写解题思路
先从第一列开始 纵向二分查找，注意不能有等于号。第二次横向二分查找。
### 代码

```python3
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False

        row = len(matrix)
        col = len(matrix[0])

        if target < matrix[0][0] or target > matrix[row - 1][col-1]:
            return False
        
        start = 0
        end = row - 1
#注意这里不可以有等号，这样最后start=end，方便我们确定数据在哪一行
        while start < end:
            mid = (start + end) // 2
            if matrix[mid][0] > target:
                end = mid - 1
            elif matrix[mid][0] < target:
                start = mid + 1
            else:
                return True
        flag = -1   
        if matrix[start][0] > target:
            flag = start -1
        elif matrix[start][0] == target:
            return True
        else:
            flag = start

        right = col - 1
        left = 0
        while left <= right:
            mid = (left + right) //2
            if matrix[flag][mid] > target:
                right = mid - 1
            elif matrix[flag][mid] < target:
                left = mid + 1
            else:
                return True
        return False
```