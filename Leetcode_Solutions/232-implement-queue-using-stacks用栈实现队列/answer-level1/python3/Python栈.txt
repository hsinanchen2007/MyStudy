### 解题思路
思考：和225题基本一样。如果入栈时为12345，队列也是12345。
添加新元素6，出栈为654321，队列却为123456。
因此这题可以转换为在出栈时将654321转换为123456的过程。
很简单，出栈之前，添加一个新栈，654321进新栈，再由新栈出栈，便成为了654321

### 代码

```python3
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.sk1 = Stack()
        self.sk2 = Stack()

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.sk1.push(x)

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if self.sk2.is_empty():
            for i in range(len(self.sk1.stack)):
                self.sk2.push(self.sk1.top())
                self.sk1.pop()
        a = self.sk2.top()
        self.sk2.pop()
        return a


    def peek(self) -> int:
        """
        Get the front element.
        """
        if len(self.sk1.stack) == 0:
            if len(self.sk2.stack) > 0:
                return self.sk2.stack[-1]
        else:return self.sk1.stack[0]

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return len(self.sk2.stack) <= 0 if len(self.sk1.stack) == 0 else False

class Stack():
    def __init__(self):
        self.stack = []

    def push(self, value):    # 进栈
        self.stack.append(value)

    def pop(self):  #出栈
        if self.stack:
            self.stack.pop()
            
    def is_empty(self): # 如果栈为空
        return len(self.stack) == 0

    def top(self):
        #取出目前stack中最新的元素
        return self.stack[-1]


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
```