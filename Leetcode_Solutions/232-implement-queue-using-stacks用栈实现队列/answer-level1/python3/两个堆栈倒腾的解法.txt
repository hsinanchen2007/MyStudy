### 解题思路
堆栈是FILO，两个堆栈组合就是FIFO。
所有的push都是从input栈操作，所有的peek和pop都是从output栈操作。

### 代码

```python3
class MyQueue:

    def __init__(self):
        self.input, self.output = [], []

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        while self.output:
                self.input.append(self.output.pop())
        self.input.append(x)
        

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        while self.input:
            self.output.append(self.input.pop())
        return self.output.pop()
        

    def peek(self) -> int:
        """
        Get the front element.
        """
        while self.input:
            self.output.append(self.input.pop())
        return self.output[-1]
        

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        while self.input:
            self.output.append(self.input.pop())
        return not self.output
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
```
![WX20191218-131446.png](https://pic.leetcode-cn.com/2dd928cb6945a3b7a84eb7a69744f70a7a157d05d68037d9eecaa01e15f4fb3a-WX20191218-131446.png)
