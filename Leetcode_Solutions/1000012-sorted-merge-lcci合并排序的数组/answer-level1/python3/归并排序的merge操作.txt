### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        C=[]
        i,j=0,0
        while i<m and j<n:
            if A[i]<=B[j]:
                C.append(A[i])
                i+=1
            else:
                C.append(B[j])
                j+=1
        while i<m:
            C.append(A[i])
            i+=1
        while j<n:
            C.append(B[j])
            j+=1
        A[:]=C[:]

```