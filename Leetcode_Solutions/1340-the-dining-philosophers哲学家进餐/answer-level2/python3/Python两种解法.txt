1. 第一种，用threading模块中的Lock()。创建锁，对每个函数的调用上锁，资源不共享，然后执行所有函数（这里是哲学家拿起叉子、吃、放下叉子），然后解锁，实现并发事件的处理。好处就是，无脑简单直观。。。缺点就是，每次上锁只能允许一个函数运行，其他并发事件得等待，也就是一次只能允许一个哲学家恰饭，其他人只能等他吃完才能吃。但是实际上当其中一个哲学家在吃的时候，不在他隔壁的哲学家也是能恰饭的，所以一定程度上降低了资源的利用率。

```
import threading
class DiningPhilosophers:
    def __init__(self):
        self.lock = threading.Lock()

    # call the functions directly to execute, for example, eat()
    def wantsToEat(self,
                   philosopher: int,
                   pickLeftFork: 'Callable[[], None]',
                   pickRightFork: 'Callable[[], None]',
                   eat: 'Callable[[], None]',
                   putLeftFork: 'Callable[[], None]',
                   putRightFork: 'Callable[[], None]') -> None:
        """
        Solution 1, using threading lock of Python
        """
        self.lock.acquire()
        pickLeftFork()
        pickRightFork()
        eat()
        putLeftFork()
        putRightFork()
        self.lock.release()
```

2. 第二种，用threading模块中的Condition()。创建条件对象cv，可以允许在符合条件的时候才继续运行线程，不然就阻塞。这里用额外的哈希表来记录每个线程的运行情况/每个哲学家的恰饭状态。当某个要恰饭的哲学家检测到他的邻居有人在恰饭，则阻塞，一直等到邻居吃完了，才开始吃。所以说，这种情况下可以同时允许多个哲学家恰饭，比如0号和2号就可以同时进食，发挥了多线程的力量，提高了资源的利用率。最后这种方法72ms，对比上一种方法的80ms有一定程度上的进步，估计是测试用例过少，导致优化程度并不是很明显。

```
import threading
class DiningPhilosophers:
    def __init__(self):
        self.cv = threading.Condition()
        # self.thread_list = [None for i in ragne(5)]
        self.d = {}
        for i in range(5):
            self.d[i] = False

    # call the functions directly to execute, for example, eat()
    def wantsToEat(self, philosopher: int, *actions) -> None:
        """
        Solution 2, using threading condition
        """
        neighbors = [philosopher - 1, philosopher + 1]
        if neighbors[0] < 0: neighbors[0] = 4
        if neighbors[1] > 4: neighbors[1] = 0

        with self.cv:
            self.cv.wait_for(lambda: not self.d[neighbors[0]] and not self.d[neighbors[1]])
            self.d[philosopher] = True

            [*map(lambda func: func(), actions)]
        
        self.d[philosopher] = False
```
