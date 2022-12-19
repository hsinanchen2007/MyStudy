```
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        if not B:
            return
        i=j=0
        while len(A)>m:
            A.pop()
        while i<m+n and j<n:
            if i >=len(A):
                A.extend(B[j:])
                break
            if B[j]<=A[i]:
                A.insert(i,B[j])
                j+=1
            else:
                i+=1
```
