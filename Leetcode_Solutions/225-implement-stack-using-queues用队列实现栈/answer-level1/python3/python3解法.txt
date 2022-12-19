### 解题思路
主要是push，考虑每次入栈的时候都把队列的元素倒过来。
### 代码

```python3
from queue import Queue

class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.que = Queue()

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.que.put(x)
        for _ in range(self.que.qsize()-1):
            self.que.put(self.que.get())

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.que.get()


    def top(self) -> int:
        """
        Get the top element.
        """
        r = self.que.get()
        self.que.put(r)
        for _ in range(self.que.qsize()-1):
            self.que.put(self.que.get())
        return r


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not self.que.qsize()



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```