### 解题思路

单个队列， push O(1), pop O(n), top O(1)

### 代码

```python
import queue
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.top_e = None
        self.cnt = 0
        self.q1 = queue.Queue()


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q1.put(x)
        self.top_e = x
        self.cnt += 1


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        i = 0
        while i < self.cnt - 2:
            i += 1
            self.q1.put(self.q1.get())
        self.top_e = self.q1.get()
        self.q1.put(self.top_e)
        self.cnt -= 1
        return self.q1.get()



    def top(self) -> int:
        """
        Get the top element.
        """
        return self.top_e


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return self.cnt == 0
```