### 解题思路
解题思路先在第一列找出所在行，再去所在行找target，查找方法都是二分查找。难点在于查找所在行时，要注意最后的结果要么是mid要么是mid-1，这里需要判断一下。

### 代码

```python3
class Solution:
    def searchMatrix(self, matrix, target: int) -> bool:
        rows = len(matrix)
        if rows==0:
            return False
        cols = len(matrix[0])
        if cols==0:
            return False
        # 在第一列上二分查找，记录所在行mid
        i=0
        j=rows-1
        while i<=j:
            mid = int((i+j)/2)
            if matrix[mid][0]>target:
                j=mid-1
            elif matrix[mid][0]==target:
                return True
            else:
                i=mid+1
        # 在所在行上二分查找
        print(mid)
        if matrix[mid][0]>target:
            mid-=1
        i=0
        j=cols-1
        while i<=j:
            mid1 = int((i+j)/2)
            if matrix[mid][mid1]>target:
                j=mid1-1
            elif matrix[mid][mid1]==target:
                return True
            else:
                i=mid1+1
        print(mid1)
        return False
```