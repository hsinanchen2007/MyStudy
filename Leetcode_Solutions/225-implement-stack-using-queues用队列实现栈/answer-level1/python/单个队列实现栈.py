### 解题思路
由于队列是FILO结构，而栈是FIFO结构。关键是模拟pop的过程中如何将原本队列的尾部元素弹出。这里其实比较简单，就只需要不断的将队首元素出队，直到原本队列尾部的元素到达队首，再进行正常的`pop`操作。值得注意的是，我们需要在这个过程中记录正确的`top_element`，也就是原本队列的导数第二个元素，因此我们循环出队直到还剩下2个元素未被操作，记录此时的队首元素为`top_element`，然后继续进行出队入队即可。

### 代码

```python3
from collections import deque

class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = deque()
        self.top_elem = None

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.stack.append(x)
        self.top_elem = x


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        size = len(self.stack)
        while size > 2:
            self.stack.append(self.stack.popleft())
            size -= 1
        
        self.top_elem = self.stack[0]
        self.stack.append(self.stack.popleft())
        return self.stack.popleft()


    def top(self) -> int:
        """
        Get the top element.
        """
        return self.top_elem


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.stack) == 0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```