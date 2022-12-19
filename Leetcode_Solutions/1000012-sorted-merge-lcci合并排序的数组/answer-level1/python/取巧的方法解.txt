### 解题思路
取巧，先加进去再排序

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
        count=m
        for i in B:
            A[count]=i
            count+=1
        A.sort()
            

```