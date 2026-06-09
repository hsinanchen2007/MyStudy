### 解题思路
1。先判断矩阵是否为空，如果为空直接返回false
2.判断目标值是否大于矩阵最大值或小于矩阵最小值。
3.对矩阵进行两次二分查找：
第一次锁定目标值可能在的行
第二次判断目标值是否在行内

### 代码

```python3
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        left = 0
        right = len(matrix) - 1
        m = 0
        if matrix == [] or matrix == [[]]:
            return False
        if target > matrix[-1][-1] or target < matrix[0][0] :
            return False
        while right >= left :
            mid = (left + right)//2
            if matrix[mid][-1] >= target and matrix[mid][0] <= target :
                m = mid
                break
            elif matrix[mid][-1] < target :
                left = mid + 1
            elif matrix[mid][0] > target :
                right = mid - 1
        nleft = 0
        nright = len(matrix[m]) - 1
        while nright >= nleft :
            nmid = (nleft + nright)//2
            if matrix[m][nmid] == target :
                return True
            elif matrix[m][nmid] < target :
                nleft = nmid + 1
            elif matrix[m][nmid] > target :
                nright = nmid - 1
        return False

        

```