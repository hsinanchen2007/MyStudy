```
import queue

class FizzBuzz:
    def __init__(self, n: int):
        self.n = n
        self.fb = queue.Queue()
        self.b = queue.Queue()
        self.f = queue.Queue()
        self.num = queue.Queue()
        self.fb.put(0)

    # printFizz() outputs "fizz"
    def fizz(self, printFizz: 'Callable[[], None]') -> None:
        for i in range(1,self.n+1):
            if self.f.get():
                if i%3 == 0:
                    printFizz()
                    self.num.put(0)
                    self.fb.put(0)
                else:
                    self.num.put(1)

    # printBuzz() outputs "buzz"
    def buzz(self, printBuzz: 'Callable[[], None]') -> None:
        for i in range(1,self.n+1):
            if self.b.get():
                if i%5 == 0:
                    printBuzz()
                    self.f.put(0)
                    self.num.put(0)
                    self.fb.put(0)
                else:
                    self.f.put(1)

    # printFizzBuzz() outputs "fizzbuzz"
    def fizzbuzz(self, printFizzBuzz: 'Callable[[], None]') -> None:
        for i in range(1,self.n+1):
            self.fb.get()
            if i%15 == 0:
                printFizzBuzz()
                self.b.put(0)
                self.f.put(0)
                self.num.put(0)
                self.fb.put(0)
            else:
                self.b.put(1)

    # printNumber(x) outputs "x", where x is an integer.
    def number(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1,self.n+1):
            if self.num.get():
                printNumber()
                self.fb.put(0)

```
