python3两个栈实现队列
```
class MyQueue:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        # Python实例方法
        self.stackPush = []
        self.stackPop = []

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.stackPush.append(x)
    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if not self.stackPop:
            while self.stackPush:
                self.stackPop.append(self.stackPush.pop())
        return self.stackPop.pop()
    def peek(self) -> int:
        """
        Get the front element.
        """
        if not self.stackPop:
            while self.stackPush:
                self.stackPop.append(self.stackPush.pop())
        return self.stackPop[-1]
    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return not bool(len(self.stackPush) or len(self.stackPop))
```
