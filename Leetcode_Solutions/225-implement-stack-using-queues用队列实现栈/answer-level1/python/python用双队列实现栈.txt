### 解题思路
此法类似官方解题思路方案一，两个队列，压入 -O(1)， 弹出 -O(n)

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q1 = []
        self.q2 = []
        self.top_data = 0

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q1.append(x)
        self.top_data = x

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        length = len(self.q1)
        for i in range(0, length - 1):
            self.q2.append(self.q1.pop(0))
        self.top_data = self.q1.pop(0)
        self.q1 = self.q2
        self.q2 = []
        return self.top_data


    def top(self) -> int:
        """
        Get the top element.
        """
        self.top_data = self.q1[len(self.q1)-1]
        return self.top_data

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.q1) == 0



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```

### 解题思路
此法类似官方解题思路方案二，两个队列， 压入 - O(n)， 弹出 - O(1)

### 代码
```
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q1 = []
        self.q2 = []
        self.top_data = 0

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q2.append(x)
        self.top_data = x
        while len(self.q1) != 0:
            self.q2.append(self.q1.pop(0))
        self.q1 = self.q2
        self.q2 = []

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.q1.pop(0)


    def top(self) -> int:
        """
        Get the top element.
        """
        return self.q1[0]

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.q1) == 0
```
