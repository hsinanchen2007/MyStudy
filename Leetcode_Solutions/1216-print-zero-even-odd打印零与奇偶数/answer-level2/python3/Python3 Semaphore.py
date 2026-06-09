```
import threading

class ZeroEvenOdd:
    s = [threading.Semaphore(0), threading.Semaphore(0), threading.Semaphore(1)]
    def __init__(self, n):
        self.n = n

	# printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(self.n):
            self.s[2].acquire()
            printNumber(0);
            self.s[i%2].release()

    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1, self.n+1, 2):
            self.s[0].acquire()
            printNumber(i)
            self.s[2].release()

    def even(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(2, self.n+1, 2):
            self.s[1].acquire()
            printNumber(i)
            self.s[2].release()
```
