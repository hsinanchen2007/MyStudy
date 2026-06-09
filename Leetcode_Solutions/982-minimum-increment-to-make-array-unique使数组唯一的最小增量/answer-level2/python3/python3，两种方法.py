方法一，排序，好理解
```
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        A.sort()
        res=0
        for i in range(1,len(A)):
            if A[i]<=A[i-1]:
                res+=A[i-1]-A[i]+1
                A[i]=A[i-1]+1
        return res
```
方法二，计数，很神奇的方法了
```
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        count=[0]*80000
        for a in A:
            count[a]+=1

        res,taken=0,0

        for i in range(0,80000):
            if count[i]>=2:
                taken+=count[i]-1
                res-=i*(count[i]-1)
            elif count[i]==0 and taken>0:
                taken-=1
                res+=i
        return res
```

