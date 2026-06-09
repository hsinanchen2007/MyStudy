### 解题思路
双指针一指向前，一指向末尾，发现符合条件的交换

### 代码

```python3
class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        n=len(A)
        start,end=0,n-1
        while start<end:
            while start<n and A[start]%2==0:
                start+=1
            while end>-1 and A[end]%2==1:
                end-=1
            if start<end:
                A[start],A[end]=A[end],A[start]
        return A




```