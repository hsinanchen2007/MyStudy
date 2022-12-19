```
class Solution:
    def nthPersonGetsNthSeat(self, n: int) -> float:
        '''
        第 n 位乘客坐在自己的座位上的概率是多少？
        设：前n-1位 坐到 n 座位概率之和为s
        1. 当 n <= 1, 概率为 1.0
        2. 当 n >= 2
        第1位 概率 s = 1/n, 第一位乘客的票丢了，他随便选了一个座位坐下
        第2位 s += s * (1/(n-1))
        ....
        第n-1位 s += s * (1/2)
        '''
        if n <= 1:
            return 1.0
        s = 1 / n
        for i in range(n-1, 1, -1):
            s += s * (1/i)
        return 1 - s
```
