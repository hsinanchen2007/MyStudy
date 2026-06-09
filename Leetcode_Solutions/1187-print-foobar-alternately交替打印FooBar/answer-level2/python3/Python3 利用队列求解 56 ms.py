Python3利用队列,foo向队列put数据,bar从队列取数据,队列的长度设置成1,数据满了put要阻塞,等数据消费了才能再次put,队列为空,要阻塞等待有数据进来.这样就保证了foo调用了之后才能调用bar,调用bar后才能调用foo
```

from queue import Queue
class FooBar:
    def __init__(self, n):
        self.n = n
        self.queue = Queue(1)

    def foo(self, printFoo: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            # printFoo() outputs "foo". Do not change or remove this line.
            self.queue.put(1)
            printFoo()



    def bar(self, printBar: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            self.queue.get()
            # printBar() outputs "bar". Do not change or remove this line.
            printBar()
```            