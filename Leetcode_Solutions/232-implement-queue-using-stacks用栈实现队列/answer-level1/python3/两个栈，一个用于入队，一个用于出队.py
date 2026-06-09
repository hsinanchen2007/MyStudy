push_stack: 用于入队
pop_stack: 用于出队

由于队列是先进先出，所以出队时，需要 `push_stack` 里的栈底元素，此时可以把 `pop_stack` 里的元素全部 pop 到 `pop_stack` 里，此时 `pop_stack` 的栈顶元素就是要出队的元素，但是只要 `pop_stack` 不为空，出队都只需要从 `pop_stack` 操作就可以了。 

```python []
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.push_stack = []
        self.pop_stack = []

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.push_stack.append(x)

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if len(self.push_stack) == 0 and len(self.pop_stack) == 0:
            return -1
        
        if len(self.pop_stack) != 0:
            return self.pop_stack.pop()
        
        while len(self.push_stack) != 0:
            self.pop_stack.append(self.push_stack.pop())
        
        return self.pop_stack.pop()

    def peek(self) -> int:
        """
        Get the front element.
        """
        if len(self.push_stack) == 0 and len(self.pop_stack) == 0:
            return -1
        
        if len(self.pop_stack) != 0:
            return self.pop_stack[-1]
        
        while len(self.push_stack) != 0:
            self.pop_stack.append(self.push_stack.pop())
        
        return self.pop_stack[-1]
        
    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return len(self.push_stack) == 0 and len(self.pop_stack) == 0
```
