```python
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = []

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.stack.append(x)

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        temp = []
        while self.stack: temp.append(self.stack.pop())
        r = temp.pop()
        while temp: self.stack.append(temp.pop())
        return r

    def peek(self) -> int:
        """
        Get the front element.
        """
        temp = []
        while self.stack: temp.append(self.stack.pop())
        r = temp[-1]
        while temp: self.stack.append(temp.pop())
        return r

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return not self.stack


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
```
- 使用俩个栈来模拟队列，当需要取第一个元素的时候创建一个临时的栈temp，把栈里面的东西全部抽出来放进temp，完成操作后放回去