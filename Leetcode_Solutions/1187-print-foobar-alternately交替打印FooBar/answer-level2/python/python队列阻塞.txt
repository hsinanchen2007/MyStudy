
```
import queue

class FooBar:

    def __init__(self, n):
        self.n = n
        self.q = queue.Queue(1) 


    def foo(self, printFoo: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            self.q.put(0)
            # printFoo() outputs "foo". Do not change or remove this line.
            printFoo()
            
            

    def bar(self, printBar: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            
            self.q.get()
            # printBar() outputs "bar". Do not change or remove this line.
            printBar()
```


