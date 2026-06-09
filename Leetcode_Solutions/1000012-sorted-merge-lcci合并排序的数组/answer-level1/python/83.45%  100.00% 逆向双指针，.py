### 解题思路
83.45%  100.00%
逆向双指针，只需要new一个长度变量
判断稍微多了点

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        lnn = m+n
        for i in range(lnn):
            if m==0 and n==0:
                return
            elif m==0:
                A[lnn-1-i]=B[n-1]
                n = n-1
            elif n==0:
                A[lnn-1-i]=A[m-1]
                m=m-1
            elif  A[m-1]>B[n-1]:
                A[lnn-1-i]=A[m-1]
                m=m-1
            else:
                A[lnn-1-i]=B[n-1]
                n=n-1
            

```