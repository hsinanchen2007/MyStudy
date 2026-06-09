### 解题思路
十大排序之简单插入排序

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
        for i in range(m,m+n):
            j=i-1
            while j>=0 and A[j]>B[i-m]:
                A[j+1]=A[j]
                j=j-1
            A[j+1]=B[i-m]
        return A
            

```