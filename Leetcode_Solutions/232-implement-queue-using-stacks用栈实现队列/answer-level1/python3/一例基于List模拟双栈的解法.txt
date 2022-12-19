### 解题思路
一种简单明了的实现方式。使用list的append，pop模拟两个栈，但这种方法时空间成本都比较高。下一步尝试Node栈解法

### 代码

```python3
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.in_stack = []
        self.out_stack = []


    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        while self.out_stack != []:
            self.in_stack.append(self.out_stack.pop())
        self.in_stack.append(x)
        return


    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        while self.in_stack != []:
            self.out_stack.append(self.in_stack.pop())
        return(self.out_stack.pop())

    def peek(self) -> int:
        """
        Get the front element.
        """
        while self.in_stack != []:
            self.out_stack.append(self.in_stack.pop())
        return(self.out_stack[-1])

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return self.out_stack == [] and self.in_stack == []


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
```