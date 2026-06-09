### 解题思路
**如何用列表模拟队列操作？**
- push——list.insert(0,val)
- pop ——list.pop()

### 代码

```python3
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.que = []

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.que.insert(0,x)

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        return self.que.pop() if self.que else None

    def peek(self) -> int:
        """
        Get the front element.
        """
        return self.que[-1] if self.que else None

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return False if self.que else True
```