题解思路：

在要跳到第N阶时，一种是n-1阶跳一阶到达n阶
第二种是从n-2阶跳两阶到达n阶
（（n-2）跳一次再跳一次属于上面那种方法）
所以到达第n阶的方法总数是到达第（n-1）的跳法加上
到达第（n-2）的跳法
利用波菲那契数列求解
注意此时波菲那契应该从1开始（到达第一阶有一种方法）
```
class Solution(object):
    def numWays(self, n):
        if n > 0:
            d = []
            c = n
            a, b = 1, 1
            while c > 0:
                d.append(b)
                a, b = b, a+b
                c -= 1
            return(d[n-1]%1000000007)
        else :
            return 1
```