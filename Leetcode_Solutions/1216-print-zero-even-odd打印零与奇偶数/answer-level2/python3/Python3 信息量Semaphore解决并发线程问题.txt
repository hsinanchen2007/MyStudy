# 函数
这一章可以很方便的使用python的threading包中的Semaphore(int initthread)函数来解决,该函数可以使用acquire(使当前线程池-1容量)和release(使当前线程池+1容量）来控制并发数量 thread，最有趣的是，当线程为零而发生acquire操作时，线程会停在此处等待线程。

# 实现方法
基于以上函数，我们就可以结合多线程使用 sum(initthread_k) =1 (k=1,2,...n)，以及acquire和release成对出现来将多线程合并为单线程，这在一定程度上会让多线程失去意义，但是，解题方便！你说呢~

# 代码

```
import threading as th
class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.z=th.Semaphore(1)
        self.e=th.Semaphore(0)
        self.o=th.Semaphore(0)
        
	# printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1,2*self.n+1):
            if i%2==1:
                self.z.acquire()
                printNumber(0)
            elif i%4==0:
                self.e.release()
            else:
                self.o.release()
        
        
    def even(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1,2*self.n+1):
            if i%4==0:
                self.e.acquire()
                printNumber(i//2)
                self.z.release()
            else:
                pass
        
        
        
    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1,2*self.n+1):
            if i%4==2:
                self.o.acquire()
                printNumber(i//2)
                self.z.release()
            else:
                pass
```

