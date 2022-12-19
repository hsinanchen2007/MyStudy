```
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows=len(matrix)
        if rows==0:
            return False
        cols=len(matrix[0])
        if cols<=0:
            return False
        rt=0;rb=rows-1
        row=None;col=None
        while rt<=rb:
            mid=rt+(rb-rt)//2
            val= matrix[mid][cols-1]
            if target == val:
                return True
            elif target > val:
                rt = mid+1
            else:
                rb = mid-1
        row=rt
        if row < 0 or row >= rows:
            return False
        if matrix[row][cols-1]<target:
            return False
        print(row)
        l=0;r=cols-1;
        while l<=r:
            mid=l+(r-l)//2
            val=matrix[row][mid]
            if val==target:
                return True
            elif val>target:
                r=mid-1
            else:
                l=mid+1
        return False
```
