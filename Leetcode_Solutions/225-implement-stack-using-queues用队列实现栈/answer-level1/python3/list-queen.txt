### 解题思路
在0处处理列表

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.Q=[]

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        return self.Q.insert(0,x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.Q.pop(0)

    def top(self) -> int:
        """
        Get the top element.
        """
        return self.Q[0]

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        if len(self.Q):return False
        else: return True


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```