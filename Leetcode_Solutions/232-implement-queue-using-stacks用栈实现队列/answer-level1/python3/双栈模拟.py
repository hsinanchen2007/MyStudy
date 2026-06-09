```
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head = []
        self.tail = []

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.tail.append(x)

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if not self.head:
            while self.tail:
                self.head.append(self.tail.pop())
        return self.head.pop()
        

    def peek(self) -> int:
        """
        Get the front element.
        """
        if self.head:
            return self.head[-1]
        elif self.tail:
            return self.tail[0]


    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return not self.head and not self.tail
```
