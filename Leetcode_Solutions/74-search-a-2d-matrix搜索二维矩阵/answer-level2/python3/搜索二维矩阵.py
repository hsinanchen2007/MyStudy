### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def searchMatrix(self,matrix,target):
        if matrix==[] or matrix[-1]==[]:return False
        lst=[]
        for i in matrix:
            if target>=i[0] and target<=i[-1]:lst=i
        if lst==[]:return False
        l,r=0,len(lst)-1
        mid=int((l+r)/2)
        while l<=r:
            if lst[mid]==target:return True
            if lst[mid]<target:
                l=mid+1
                mid=int((l+r)/2)
            if lst[mid]>target:
                r=mid-1
                mid=int((l+r)/2)
        return False
```