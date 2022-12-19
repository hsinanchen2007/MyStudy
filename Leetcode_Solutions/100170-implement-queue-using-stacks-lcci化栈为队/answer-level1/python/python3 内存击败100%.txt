### 解题思路
用的list
### 代码

```python3
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.values=[]

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.values.append(x)

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        return_pop=self.values[0]
        self.values.pop(0)
        return return_pop
    def peek(self) -> int:
        """
        Get the front element.
        """
        return self.values[0]

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return self.values==[]


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
```