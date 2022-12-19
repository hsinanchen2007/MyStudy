### 解题思路


### 代码

```python3
class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        i=0
        j=1
        while i<len(A) and j<len(A):
            if A[i]%2==1 and A[j]%2==0 : A[i],A[j]=A[j],A[i]
            if A[i]%2==0:i+=2
            if A[j]%2==1:j+=2
        return A
```