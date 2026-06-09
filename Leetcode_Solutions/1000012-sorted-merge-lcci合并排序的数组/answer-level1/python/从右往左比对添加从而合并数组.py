### 解题思路
从小往大合并比较麻烦，由于A已给出合适的空间，因此从大往小进行合并更为方便。

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
        i = m-1
        j = n-1
        while j>=0:
            if i>=0:
                if A[i]>=B[j]:
                    A[i+j+1]=A[i]
                    i = i-1
                else:
                    A[i+j+1]=B[j]
                    j = j-1
            else:
                A[j]=B[j]
                j=j-1
        return A
```