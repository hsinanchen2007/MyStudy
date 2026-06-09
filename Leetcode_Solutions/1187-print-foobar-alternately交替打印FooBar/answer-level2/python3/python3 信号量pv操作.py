### 解题思路
import threading
s=threading.Semaphore(1)#1代表计数器
s.acquire()#p操作，减一，如果小于0阻塞
s.release()#v操作，加一，如果大于等于0则说明有线程在等待

### 代码

```python3
import threading 
class FooBar:
    def __init__(self, n):
        self.n = n
        self.s1=threading.Semaphore(1)
        self.s2=threading.Semaphore(0)


    def foo(self, printFoo: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            
            # printFoo() outputs "foo". Do not change or remove this line.
            self.s1.acquire()
            printFoo()
            self.s2.release()


    def bar(self, printBar: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            
            # printBar() outputs "bar". Do not change or remove this line.
            self.s2.acquire()
            printBar()
            self.s1.release()
```