
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
        while(self.queue_push.qsize() > 1):
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


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```