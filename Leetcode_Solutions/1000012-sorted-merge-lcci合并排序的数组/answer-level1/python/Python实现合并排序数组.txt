解题思路: 逆向合并

具体方法: 一般有序数组的合并是从前往后, 不过此题如果从前往后, 必须开辟新的空间存储被覆盖的数据。如果从后往前, 因为后面的空间尚未使用, 可以直接存储当前最大值。空间复杂度降为O(1)

代码:
```
class Solution(object):
    def merge(self, A, m, B, n):
        """
        :type A: List[int]
        :type m: int
        :type B: List[int]
        :type n: int
        :rtype: None Do not return anything, modify A in-place instead.
        """
        i, j, k = m - 1, n - 1, m + n - 1
        while i >= 0 and j >= 0:
            if A[i] > B[j]:
                A[k] = A[i]
                i -= 1
            else:
                A[k] = B[j]
                j -= 1
            k -= 1
        while j >= 0:
            A[k] = B[j]
            j -= 1
            k -= 1
```