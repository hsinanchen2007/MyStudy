### 解题思路
原地修改

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        p,q,tail = m-1,n-1,m+n-1
        while p >= 0 or q >= 0:
            if p == -1:
                A[tail] = B[q]
                q -= 1
            elif q == -1:
                A[tail] = A[p]
                p -= 1
            elif A[p] < B[q]:
                A[tail] = B[q]
                q -= 1
            else:
                A[tail] = A[p]
                p -= 1
            tail -= 1
        

```