### 解题思路

从后往前比较

### 代码

```python
class Solution(object):
    def merge(self, A, m, B, n):
        """
        :type A: List[int]
        :type m: int
        :type B: List[int]
        :type n: int
        :rtype: None Do not return anything, modify A in-place instead.
        """

        p = len(A)
        while m and n:
            if A[m-1]>B[n-1]:
                A[p-1]=A[m-1]
                m -= 1
            else :
                A[p-1]=B[n-1]
                n -= 1
            p -= 1
        while n:
            A[n-1]=B[n-1]
            n -= 1
```