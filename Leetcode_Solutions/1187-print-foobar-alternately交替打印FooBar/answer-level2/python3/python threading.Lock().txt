思想都一样，用两把锁控制两个进程的执行顺序，每个进程打印一个字符串后将两把锁反转，将自己停止，解锁另一个进程，把控制交给另一个进程。同样，另一个进程打印完后，将自己停止，解锁之前的进程，把控制交给之前的进程。

用到了`threaing.Lock()`

```python
import threading
class FooBar:
    def __init__(self, n):
        self.n = n
        self.lockfool = threading.Lock()
        self.lockbar = threading.Lock()
        self.lockbar.acquire()

    def foo(self, printFoo: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            # printFoo() outputs "foo". Do not change or remove this line.
            self.lockfool.acquire()
            printFoo()
            self.lockbar.release()
            

    def bar(self, printBar: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            self.lockbar.acquire()
            # printBar() outputs "bar". Do not change or remove this line.
            printBar()
            self.lockfool.release()
```