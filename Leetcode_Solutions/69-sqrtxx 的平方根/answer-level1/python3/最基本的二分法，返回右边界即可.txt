用普通的二分法就行。如果结果为小数的话，跳出循环时最后执行的一定是r=mid-1,使得r>l才能跳出循环。
比如求5的平方根，最后会验证mid=3的情况，此时l=r=3，而3的平方大于5，于是执行r=mid-1，结果为2。
```
class Solution:
    def mySqrt(self, x: int) -> int:
        l=0
        r=x
        while l<=r:
            mid=l+(r-l)//2
            if mid*mid==x:
                return mid
            elif mid*mid>x:
                r=mid-1
            else:
                l=mid+1
        return r
```

