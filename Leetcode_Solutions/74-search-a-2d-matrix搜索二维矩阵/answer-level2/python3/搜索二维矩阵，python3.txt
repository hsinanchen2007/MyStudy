### 解题思路
如果target存在于矩阵当中，先找到target位于应该第几行
然后在该行使用二分查找

### 代码

```python3
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False
        if not matrix[0]:
            return False
        flag = False
        for i in range(len(matrix)):
            if matrix[i][-1] == target:
                return True
            elif matrix[i][-1] < target:
                continue
            else:
                flag = True
                break
        if flag is False:
            return False
        start, end = 0, len(matrix[i])-1
        while start <= end:
            mid = (start+end)//2
            #print(start, mid, end)
            if matrix[i][mid] == target:
                return True
            elif matrix[i][mid] > target:
                end = mid-1
            else:
                start = mid+1
        return False
```