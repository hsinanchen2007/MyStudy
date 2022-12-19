```Python
from threading import Condition
class FooBar:
    def __init__(self, n):
        self.n = n
        self.con = Condition()


    def foo(self, printFoo: 'Callable[[], None]') -> None:
        self.con.acquire()
        #print('foo start')

        for _ in range(self.n):
            self.con.wait()
            printFoo()
            self.con.notify()

        self.con.release()


    def bar(self, printBar: 'Callable[[], None]') -> None:
        self.con.acquire()
        #print('bar start')
        
        for _ in range(self.n):
            self.con.notify()
            self.con.wait()
            printBar()
            
        self.con.release()
```

