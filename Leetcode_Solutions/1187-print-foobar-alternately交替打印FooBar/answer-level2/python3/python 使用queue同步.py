### 解题思路
没什么好说的，两个函数对应两个queue,queue为空时函数阻塞，控制queue弹出塞入元素即可

### 代码

```python3
import queue

class FooBar:
    def __init__(self, n):
        self.n = n
        self.q1 = queue.Queue()
        self.q2 = queue.Queue()
        self.q1.put(0)


    def foo(self, printFoo: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            self.q1.get()
            # printFoo() outputs "foo". Do not change or remove this line.
            printFoo()
            self.q2.put(0)


    def bar(self, printBar: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            self.q2.get()
            # printBar() outputs "bar". Do not change or remove this line.
            printBar()
            self.q1.put(0)
```