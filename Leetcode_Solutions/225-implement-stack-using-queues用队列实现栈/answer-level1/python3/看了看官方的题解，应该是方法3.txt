### 解题思路
看了看官方的题解，应该是方法3

### 代码

```python3
import queue
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        # 只能使用appendleft和pop，以及
        self.q = queue.deque()
        self.count = 0

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q.appendleft(x)
        for _ in range(self.count):
            self.q.appendleft(self.q.pop())
        self.count += 1

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        self.count -= 1
        return self.q.pop()

    def top(self) -> int:
        """
        Get the top element.
        """
        return self.q[-1]        

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.q)==0

# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```