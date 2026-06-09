```
from threading import Lock
class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.num = 0
        self.lzero = Lock()
        self.leven = Lock()
        self.lodd = Lock()
        self.leven.acquire()
        self.lodd.acquire()
        
        
	# printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        for x in range(self.n):
            self.lzero.acquire()
            printNumber(0)
            self.num += 1
            if self.num % 2 == 0:
                self.leven.release()
            else:
                self.lodd.release()
        
        
        
    def even(self, printNumber: 'Callable[[int], None]') -> None:
        for x in range(2, self.n+1, 2):
            self.leven.acquire()
            printNumber(self.num)
            self.lzero.release()
        
        
        
    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        for x in range(1,self.n+1, 2):
            self.lodd.acquire()
            printNumber(self.num)
            self.lzero.release()
```

