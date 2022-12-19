解题思路：
从尾部倒序归并，只需要一次扫描。
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
        l,r,e = m-1,n-1,len(A)-1
        while l >= 0 and r >= 0:
            if A[l] >= B[r]:
                A[e]=A[l]
                l -= 1
            else:
                A[e]=B[r]
                r -= 1
            e -= 1
        for i in range(r+1):
            A[i] = B[i]
        
```
