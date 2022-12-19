```
from math import gcd
class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        #三数最小公倍数=两数最小公倍数与第三个数的最小公倍数
        def Lcm3(x,y,z):
            a = (x*y)//gcd(x,y)  
            return (a*z)//gcd(a,z)
        '''
        计算有多少个丑数小于等于x
        + x整除a,b,c -整除ab,bc,ac最小公倍数 +整除abc最小公倍数 即为所求
        '''
        def uglynum(x):
                return x//a+x//b+x//c-x//(a*b//gcd(a,b))-x//(a*c//gcd(a,c))-x//(b*c//gcd(b,c))+x//Lcm3(a,b,c)
        '''
        二分搜索，注意只要uglynum(mid)<n left就=mid+1 所以最后得到的left就是所求
        例如测试用例2中  a=2,b=3,c=4
        括号中为丑数                    1,(2),(3),(4),5,(6),7,(8)
        小于等于它们的丑数个数分别为     0, 1 , 2 , 3 ,3, 4, 4, 5 
        若n==4
        如果uglynum(mid)<4 则left一定能直接取到6而不是7
        '''
        left=1
        right=n*min(a,b,c)
        while left<right:
            mid=(left+right)//2
            if uglynum(mid)<n:
                left=mid+1
            else:
                right=mid
        return left
```
