先排序，后二分搜0位置，后先正数求和，再从负数中较大的加进来
```
class Solution:
    def maxSatisfaction(self, satisfaction):
        num = sorted(satisfaction)
        i_0 = self.bisect_zero(num)
        if i_0==-1:
            return 0
        neg = num[:i_0]
        pos = num[i_0:]
        res = sum(pos[i]*(i+1) for i in range(len(pos)))
        s_p = sum(pos)###“后面”的数组求和
        if i_0==0:
            return res
        while i_0-1>=0 and num[i_0-1]+s_p+res>res:
            res = num[i_0-1]+s_p+res
            s_p+=num[i_0-1]
            i_0 -= 1
        return res
    
    def bisect_zero(self,A):
        start,end = 0,len(A)-1
        while start+1<end:
            mid = (start+end)//2
            if A[mid]<0:
                start = mid
            else:
                end = mid
        if A[start]>=0:
            return start  
        if A[end]>=0:
            return end
        return -1
```
