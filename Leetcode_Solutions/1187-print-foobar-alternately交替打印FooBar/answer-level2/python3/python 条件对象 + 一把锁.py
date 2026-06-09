```
from threading import Lock, Condition
class FooBar:
    def __init__(self, n):
        self.n = n
        self.num = 0 
        self.cv = Condition()

    def foo(self, printFoo: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            with self.cv:
                while self.num % 2 == 1:
                    self.cv.wait()
                printFoo()
                self.num += 1
                self.cv.notify()
            

    def bar(self, printBar: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            with self.cv:
                while self.num %2 == 0:
                    self.cv.wait()
                # printBar() outputs "bar". Do not change or remove this line.
                printBar()
                self.num += 1
                self.cv.notify()
```
