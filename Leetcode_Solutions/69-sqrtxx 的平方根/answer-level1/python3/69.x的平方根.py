思路：x<=1的时候，返回x就行了。
其他时候，查找中位数m，当中位数和头s相等的时候，说明该中位数是题解。
所以当s!=m的时候，进行分析m是否为题解，如果结果等于m，则返回m，如果大于m，则说明题解在[m,e]之间，小于m，则在[s,m]之间。
（具体为什么我也不懂，就是发现是这样，小白一个）
```
class Solution:
    def mySqrt(self, x: int) -> int:
        if x <= 1:
            return x
        s = 1
        e = x
        m = (s + x) // 2
        while s != m:
            if x // m == m :
                return m
            elif x // m > m:
                s = m 
                m = (s + e) // 2
            else:
                e = m
                m = (s + e) // 2
        return m
```
