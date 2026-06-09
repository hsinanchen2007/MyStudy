**方法一，锁阻塞：**

属于吃完一个到一个的非并行方法，只是通过阻塞解决了执行顺序的问题。

`Lock`也行，`threading`模块的其他阻塞方法比如说信号量`Semaphore`之类的也行，最快可以达到76ms这样。

通过`*actions`来代替多函数指针参数，遍历时加括号运算符即可执行。

```python []
import threading

class DiningPhilosophers:
    
    def __init__(self):
        self.l = threading.Lock()

    def wantsToEat(self, philosopher, *actions):
        self.l.acquire()
        [*map(lambda func: func(), actions)]
        self.l.release()
```

**方法二，队列：**

轮流吃面，整进整出，每次唤醒一个哲学家都会从队列里吃一次完整的面，就算在输出过程中并行的使用`pop`也没关系，只要在操作数组尾部添加数据时线程安全就不需要进行阻塞，当然，`pop`操作本身也是线程安全的。

Python下`threading`模块的单次阻塞在毫秒数量级这样，测试用例多了，这种不需要额外阻塞的方法可能就显得快了，60ms仅供参考。

![image.png](https://pic.leetcode-cn.com/4ce07441324c0ac2d60a8117d69d5d9e221d786a1a3678671b74ff87470ebabb-image.png)


```python []
class DiningPhilosophers:
    
    def __init__(self):
        self.actions = []
        
    def wantsToEat(self, philosopher, *actions):
        self.actions += actions
        [*map(lambda _: self.actions.pop(0)(), actions)]
```
```python []
class DiningPhilosophers:
    
    def __init__(self):
        self.actions = collections.deque()
        
    def wantsToEat(self, philosopher, *actions):
        self.actions.extend(actions)
        [*map(lambda _: self.actions.popleft()(), actions)]
```


**方法三，条件阻塞：**

交替吃面，只要不是邻座就可以一起吃面，理论上的正统解法之一，可以算是服务员分配吃面权限的解法。

或因为计算复杂，或因为Python乐色的多线程特性，即使交替吃面了，速度也快不上来，最快88ms这样，大部分在100ms以上，或许哲学家多点会快点吧。

原理就是通过对`self.t`的加减计算进行线程条件监控，符合吃面条件的时候就可以一起吃面。

例如`philosopher == 0`号哲学家首先被唤醒时，判断`self.t == 0 in self.d[philosopher] == {0, 7, 8}`的情况，如果是，`self.t += philosopher + 5` ，即 `self.t == 5`，这样就可以在下一个哲学被唤醒时进行判断，假设下一个哲学家为`philosopher == 2`号哲学家，发现`self.t == 5 in self.d[philosopher] == {0, 9, 5}`是符合条件的，这时 `self.t += philosopher + 5` ，即`self.t = 5 + 7 == 13`，`13`不在任何一个满足条件的集合中，故也不会再唤醒其他哲学家，直到`0`号或`2`号哲学家执行完毕，`self.t` 变小时才有可能满足条件唤醒其他哲学家的线程，这样就可以完成哲学家的交替吃面了。

在测试过程发现题目其实也有BUG，就是同一个哲学家多次吃面时，发生理论上的自锁（同一个哲学家同时吃不同批次的面）并不判错。

```python []
import threading

class DiningPhilosophers:
    
    def __init__(self):
        self.c = threading.Condition()
        self.d = [{0, 7, 8}, {0, 8, 9}, {0, 9, 5}, {0, 5, 6}, {0, 6, 7}]
        self.t = 0
        
    def wantsToEat(self, philosopher, *actions):
        with self.c:
            self.c.wait_for(lambda: self.t in self.d[philosopher])
            self.t += philosopher + 5
            self.c.notify_all()
        [*map(lambda func: func(), actions)]
        with self.c:
            self.t -= philosopher + 5
            self.c.notify_all()
```
