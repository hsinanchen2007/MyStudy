### 解题思路
sort排序，然后遍历一遍，小了加差值加一即可完成

### 代码

```python
class Solution(object):
    def minIncrementForUnique(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        n = len(A)
        if  n == 0:
            return 0
        A.sort()
        res = 0
        for i in range(1,n):
            if A[i] <= A[i-1]:
                dif = A[i-1]-A[i]+1
                A[i] = A[i-1]+1
                res += dif
        return res
```