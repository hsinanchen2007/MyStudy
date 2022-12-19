### 合并排序数组


```
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        L = m+n-1
        while L>-1 and m>0 and n>0:
            if A[m-1]>=B[n-1]:
                A[L]=A[m-1]
                m-=1
            else:
                A[L] = B[n-1]
                n-=1
            L-=1
        A[0:n]=B[0:n]
```
