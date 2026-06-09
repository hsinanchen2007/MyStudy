### 打卡
此处撰写解题思路

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.a = []


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.a.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.a.pop()


    def top(self) -> int:
        """
        Get the top element.
        """
        return self.a[-1]


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return False if len(self.a) > 0 else True



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(["MyStack","push","push","top","pop","empty"])
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```