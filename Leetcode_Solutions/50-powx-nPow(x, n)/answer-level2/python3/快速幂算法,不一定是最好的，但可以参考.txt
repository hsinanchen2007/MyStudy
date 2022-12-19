例如：
2^(7) = 2^(111B) = 2^(2^0) * 2^(2^1) * 2^(2^2) = a1 * a2 * a3
2^(13)= 2^(1101B)= 2^(2^0) * 2^(2^2) * 2^(2^3) = a1 * a3 * a4
a(i+1) = a(i)*a(i)
```
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n<0:
            flag=0
            n = abs(n)
        else:
            flag=1
        low = n - ((n>>1)<<1)
        res = 1
        while n:
            if low == 1:
                res*=x
            x*=x
            n>>=1
            low = n - ((n>>1)<<1)
        if flag==1:
            return res
        else:
            return 1/res
if __name__ == '__main__':
    s = Solution()
    res=s.myPow(2.0, -2)
    print(res)
```
