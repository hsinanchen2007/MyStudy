### 解题思路
一定会在循环内返回的（<=）
需要注意细节几点，见代码

### 代码

```python
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m,n, A,B = len(nums1),len(nums2),nums1,nums2
        if m>n:# j = halfLen-i
            m,n,A,B = n,m,B,A
        imin,imax,halfLen = 0,m,(m+n+1)//2 #//
        while imin <= imax: #=
            i = (imin+imax)//2 #//
            j = halfLen-i #i large j <0
            if i<m and B[j-1]>A[i]:
                imin = i + 1
            elif i>0 and A[i-1]>B[j]:
                imax= i -1
            else :
                if i ==0:
                    left_max = B[j-1]
                elif j == 0:
                    left_max = A[j-1]
                else:
                    left_max = max(A[i-1],B[j-1])
                if (m+n)%2==1:
                    return left_max
                if i ==m: right_min = B[j]
                elif j==n: right_min = A[i]
                else : right_min = min(A[i],B[j])
                return (left_max+right_min)/2



```