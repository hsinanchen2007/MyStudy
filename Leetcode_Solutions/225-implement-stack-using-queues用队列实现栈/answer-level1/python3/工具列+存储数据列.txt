### 解题思路
queue1用来存放数据，每次入栈就插入queue1索引值为0的地方。queue2为出栈时的辅助工具队列，将queue1[1:-1]的元素出队然后入队queue2(也就是queue1逆序压入queue2)，当queue1仅剩队首元素，这个时候出队即出栈。

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue1 = []
        self.queue2 = []


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.queue1.insert(0, x)

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        for _ in range(len(self.queue1) - 1):
            self.queue2.insert(0, self.queue1.pop())
        res = self.queue1.pop()
        self.queue1 = self.queue2
        self.queue2 = []
        return res



    def top(self) -> int:
        """
        Get the top element.
        """
        self.queue2 = self.queue1[:]
        for i in range(len(self.queue1) - 1):
            self.queue1.pop()
        res = self.queue1[-1]
        self.queue1 = self.queue2
        self.queue2 = []
        return res


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        if len(self.queue1) == 0:
            return True
        return False




# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```