整体思路我觉得看代码最清楚，代码也比较简单，我就不详细解释了
### 方法一
```
from queue import Queue

class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue_push = Queue()
        self.queue_pop = Queue()

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.queue_push.put(x)
        self.top_ele = x

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        while (self.queue_push.qsize() > 1):
            self.top_ele = self.queue_push.get()
            self.queue_pop.put(self.top_ele)
        res = self.queue_push.get()
        self.queue_pop, self.queue_push = self.queue_push, self.queue_pop
        return res

    def top(self) -> int:
        """
        Get the top element.
        """
        return self.top_ele

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return self.queue_push.empty() and self.queue_pop.empty()

```
### 方法二
```
from queue import Queue

class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue_push = Queue()
        self.queue_pop = Queue()

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.queue_push.put(x)
        self.shift()

    def shift(self):
        while (self.queue_pop.qsize()):
            self.queue_push.put(self.queue_pop.get())

        self.queue_pop, self.queue_push = self.queue_push, self.queue_pop

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """

        return self.queue_pop.get()

    def top(self) -> int:
        """
        Get the top element.
        """
        ##很奇怪，在python3中queue好像没有类似于top/peek的方法
        self.top_ele = self.queue_pop.get()
        self.push(self.top_ele)
        return self.top_ele
```
### 方法三
```
from queue import Queue

class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue_push = Queue()

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.queue_push.put(x)
        size = self.queue_push.qsize()
        while (size>1):
            self.queue_push.put(self.queue_push.get())
            size -= 1


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """

        return self.queue_push.get()

    def top(self) -> int:
        """
        Get the top element.
        """
        ##很奇怪，在python3中queue好像没有类似于top/peek的方法
        top = self.queue_push.get()
        self.push(top)
        return top

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return self.queue_push.empty()
```
