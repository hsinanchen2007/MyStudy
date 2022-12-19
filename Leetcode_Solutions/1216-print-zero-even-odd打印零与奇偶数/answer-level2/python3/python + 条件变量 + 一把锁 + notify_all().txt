执行用时 :
124 ms
, 在所有 Python3 提交中击败了
50.00%
的用户

内存消耗 :
15.5 MB
, 在所有 Python3 提交中击败了
100.00%
的用户。

最后结果2n个数，其中n个0.

多少个奇数呢？自己写写就能推理出来 $(self.n+1)//2$.
然后剩下的是偶数: $self.n - (self.n+1)//2$

最后的问题：什么时候输出偶数，什么时候输出奇数：
输出数字`01020304`
index  `01234567`

对比你会发现 被4除余数为3的位置输出偶数，余数为1的位置输出奇数


```
from threading import Lock, Condition
class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.num = 0
        self.cv = Condition()
        
        
	# printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(self.n):
            with self.cv:
                while self.num % 2 != 0:
                    self.cv.wait()
                printNumber(0)
                self.num += 1
                self.cv.notify_all()
        
        
    def even(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(self.n - (self.n+1)//2):
            with self.cv:
                while self.num % 4 !=3:
                    self.cv.wait()
                printNumber((self.num+1)//2)
                self.num += 1
                self.cv.notify_all()    
        
        
    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range((self.n+1)//2):
            with self.cv:
                while self.num % 4 != 1:
                    self.cv.wait()
                printNumber((self.num+1)//2)
                self.num += 1
                self.cv.notify_all()
```
