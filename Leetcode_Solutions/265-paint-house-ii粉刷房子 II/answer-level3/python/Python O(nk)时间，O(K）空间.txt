思想跟粉刷房子差不多，实现的时候需要一个辅助函数
```
class Solution:
    def minCostII(self, C: List[List[int]]) -> int:
        if not C:
            return 0
        if len(C)==1:
            return min(C[0])
        def minExceptSelf(a):
            mi=min(a)
            ans=[mi]*len(a)
            if a.count(mi)==1:
                idx=a.index(mi)
                a.remove(mi)
                ans[idx]=min(a)
            return ans
        
        k=len(C[0])
        cur=[0]*k
        for c in C:
            last=minExceptSelf(cur)
            cur=[c[i]+last[i] for i in range(k)]
        return min(cur)
```
