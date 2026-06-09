首先确定可能需要的步数，最多的步数为n步，每步一阶楼梯；最少的步数为(n+1)//2步，每步走两阶楼梯，最后为0或者1步。
接着求步数为ii时的可能的情况，最后相加即可。
```
class Solution:
    def climbStairs(self, n: int) -> int:
        if n==1 or n==2:
            return n
        ls = (n+1)//2
        res=1 #走n步时只有一种情况
        for ii in range(ls,n): #可能需要的步数
            cval1 = 1
            cval2 = 1
            for jj in range(1,n-ii+1): #求组合数
                cval1*=jj
                cval2*=(ii-jj+1)
            cval = cval2/cval1
            res+=cval
        return int(res) 
```
用时36ms