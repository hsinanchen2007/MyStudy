### 解题思路
栈是先进后出，想象成一堆由上到下摞起来的碗，我们想要拿碗的话就要先那最顶上的再拿最底下的，当然这里假设我们都是正常人；然后队列就是不正常人的情况：一堆碗由高到低摞在一起，非要先把最底下的碗拿出来，从下往上拿，脑子有坑~
记清楚基本逻辑之后其实代码还是很好实现的。

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q = collections.deque()

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q.append(x)
        for _ in range(len(self.q) - 1):
            self.q.append(self.q.popleft())
        

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.q.popleft()
        

    def top(self) -> int:
        """
        Get the top element.
        """
        return self.q[0]

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not(len(self.q))
        


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```