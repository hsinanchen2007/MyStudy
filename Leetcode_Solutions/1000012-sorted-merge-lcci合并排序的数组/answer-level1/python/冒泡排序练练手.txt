### 解题思路
此处撰写解题思路

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
        for i in range(len(B)):
            A[-i-1]=B[i]
        for i in range(len(A)-1):
            for j in range(0,len(A)-1-i):
                if A[j]>A[j+1]:
                    A[j],A[j+1]=A[j+1],A[j]
        return A

```