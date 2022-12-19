**本质就是生产者与消费者问题，foo是生产者，bar是消费者，要先生产才能被消费，且商品缓冲区上限为1**
```
import threading
empty=threading.Semaphore(1) # empty信号量初始值设为1  空缓冲区数量
full=threading.Semaphore(0)  # full 信号量初始值设为0  满缓冲区数量
'''信号量为0时，不可被减，同时信号量不设上限
所以需要两个信号量empty、full共同监测两个边界[0,1]'''

class FooBar:
    def __init__(self, n):
        self.n = n


    def foo(self, printFoo: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            empty.acquire() # empty-1，申请一个空缓冲区，有空位时应执行生产者活动
            printFoo()
            full.release() # full+1，释放一个满缓冲区


    def bar(self, printBar: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            full.acquire() # full-1, 申请一个满缓冲区，当缓冲区有商品时才能实现消费者行为
            printBar()
            empty.release() # empty+1，释放一个空缓冲区
```
