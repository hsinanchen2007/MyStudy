### 解题思路
从两边向内找，如果两边是三分之一的总和，那么中间必定也是

### 代码
```
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        s=sum(A)
        if s%3!=0:
            return False
        left=right=0
        i,j=0,len(A)-1
        avg=s/3
        while left!=avg and i<len(A):
            left+=A[i]
            i+=1
        while right!=avg and j>-1:
            right+=A[j]
            j-=1
        if i<=j and left==right==avg:
            return True
        return False
```
