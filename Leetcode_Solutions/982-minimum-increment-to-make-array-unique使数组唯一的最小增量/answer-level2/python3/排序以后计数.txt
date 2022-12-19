先对A进行排序，然后再对A相邻的元素进行判断即可。
```
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        A.sort()
        if len(A)<=1: return 0 
        num=0
        for i in range(1,len(A)):
            if A[i]<=A[i-1]:
                num+=A[i-1]-A[i]+1
                A[i]=A[i-1]+1
        return num
```
