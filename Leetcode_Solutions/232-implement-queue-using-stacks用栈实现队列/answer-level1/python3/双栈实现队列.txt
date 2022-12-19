### 解题思路
用一个缓存栈去保存原数据域中的数据，对原数据域中的数据进行反转存储，以实现队列FIFO特性

### 代码

```python3
class MyQueue:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        # 数据域
        self.data = []
        # 缓存
        self.cache = []

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        # 翻转数据域
        while not self.empty():
            self.cache.append(self.data.pop(-1))
        self.data.append(x)
        while self.cache:
            self.data.append(self.cache.pop(-1))

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        return self.data.pop(-1)

    def peek(self) -> int:
        """
        Get the front element.
        """
        return self.data[-1]

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return not self.data
```