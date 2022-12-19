```
import threading

class FooBar:
    sf1, sf2 = threading.Semaphore(1), threading.Semaphore(0)
    def __init__(self, n):
        self.n = n

    def foo(self, printFoo: 'Callable[[], None]') -> None:
        for i in range(self.n):
            self.sf1.acquire()
            # printFoo() outputs "foo". Do not change or remove this line.
            printFoo()
            self.sf2.release()

    def bar(self, printBar: 'Callable[[], None]') -> None:
        for i in range(self.n):
            self.sf2.acquire()     
            printBar()
            self.sf1.release()   
            
```
