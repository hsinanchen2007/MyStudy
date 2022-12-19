## 使用Python的Queue队列
Queue对象通用方法：
- Queue.qsize()
- Queue.empty()
- Queue.put(item)
- Queue.get()
有了这几个就可以了

重点关注push()的实现中，放入一个数据之后，将队列中原有数据按照顺序移动到队尾


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
        qsize = self.queue_push.qsize()
        while (qsize>1):
            self.queue_push.put(self.queue_push.get())
            qsize -= 1
        

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.queue_push.get()

    def top(self) -> int:
        """
        Get the top element.
        """
        top = self.queue_push.get()
        self.push(top)
        return top
        

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        # print(self.queue.get())
        return self.queue_push.empty()

```
