### 解题思路
通过两个队列来实现栈
push操作可以直接由queue.put完成
同时保存最后一个Push的元素就是栈顶top
而进行pop操作时需要把push队列中的元素都先取出来（FIFO）
留下最后一个元素就是真正需要pop出来的元素
完成后要把push队列和pop队列重置一下 保证pop是空队列
top 和 empty就很简单了

### 代码

```python3
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
            self.top_ele = self.queue_push.get()    #一直获取push中的ele，直到push中没有元素为止
            self.queue_pop.put(self.top_ele) #把已经取出的元素放入pop中 
        res = self.queue_push.get() #剩下的最后一个元素 就是top元素
        self.queue_pop, self.queue_push = self.queue_push, self.queue_pop   #push此时其实已经为空了，所以重置 
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