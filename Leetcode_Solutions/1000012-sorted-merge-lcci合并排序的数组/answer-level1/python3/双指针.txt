### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        t = m + n - 1
        m = m - 1
        n = n - 1
        while m>=0 or n>=0:
            if m == -1:
                A[t] = B[n]
                n -= 1 
            elif n == -1:
                A[t] = A[m]
                m -= 1
            elif A[m]>=B[n]:
                A[t] = A[m]
                m -= 1
            elif A[m]<B[n]:
                A[t] = B[n]
                n -= 1
            t -=1

```