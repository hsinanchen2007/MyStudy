### 解题思路
使用list内置函数好像就能通过了，不知道是不是有什么思维误区，欢迎指正:)。同样也能轻松通过225题（Implement Stack using Queues）。

### 代码

```python3
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue=[]


    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.queue.append(x)


    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        return self.queue.pop(0)


    def peek(self) -> int:
        """
        Get the front element.
        """
        return self.queue[0]


    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return self.queue==[]



# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
```