### 解题思路
python 基本数据结构中没有stack，不过我们通过封装list可以很容易实现stack数据结构的基本功能。


### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data = []


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.data.append(x)

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        if len(self.data) > 0:
            return self.data.pop()
        else:
            return None

    def top(self) -> int:
        """
        Get the top element.
        """
        if len(self.data) > 0:
            return self.data[len(self.data)-1]
        else:
            return None

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        if len(self.data) > 0:
            return False
        else:
            return True


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```