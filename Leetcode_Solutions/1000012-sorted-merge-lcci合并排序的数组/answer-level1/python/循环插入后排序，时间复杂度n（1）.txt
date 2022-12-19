### 解题思路
基本用法，两列表合并后排序即可

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
        k =0
        while n-k >0:
            A[m+k] = B[k]
            k+=1
        A.sort()
        return A
```