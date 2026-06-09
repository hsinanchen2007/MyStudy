```
class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        # 1337 = 7 * 191
        # a**b mod pq
        a = a%1337
        if a==0:
            return 0
        n = 570 # n = lcm(p-1,q-1)
        if a%7==0:
            n = 190
        elif a%191==0:
            n = 6
        # bexp = b mod n
        bexp = 0
        exp = 1
        b.reverse()
        for digit in b:
            bexp = (bexp + digit * exp) % n
            exp = (10*exp) % n
        # res = a ** bexp mod 1337
        def fast(bexp):
            if bexp == 0:
                return 1
            fres = fast(bexp>>1)
            if bexp & 1 == 1:
                return (a*fres*fres)%1337
            return (fres*fres)%1337
        return fast(bexp)
```
难点在于知道 a 的循环次数。如果没有数学的帮忙，我们只能通过计算机硬算；
通过因式分解，1337等于191*7,两个质数；首先我们可以先把a缩小到1337以内；
假设a有7或者191的因子，我们把问题化归成费马小定理，即
`a**(p-1)==1(mod p)`p为质数。
所以循环次数为p-1;
如果a与1337互质，我们可以证明循环次数为lcm(p-1,q-1)。详细请看[https://zh.wikipedia.org/wiki/%E5%8D%A1%E9%82%81%E5%85%8B%E7%88%BE%E5%87%BD%E6%95%B8]()
之后就很简单啦，把b缩小到n之内，然后用快速幂即可。