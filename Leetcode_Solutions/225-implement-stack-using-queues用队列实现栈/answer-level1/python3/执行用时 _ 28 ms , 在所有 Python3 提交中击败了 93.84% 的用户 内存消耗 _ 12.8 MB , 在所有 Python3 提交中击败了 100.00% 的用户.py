### 解题思路
该题在于明白栈的性质以及定义：
    栈的性质：先进后出
        犹如一个桶形容器，进去之后就会压入栈底，要出来只有等栈顶所有元素出栈才ok
    栈的应用：缓冲区、括号匹配、接迷宫

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.mylist = []

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.mylist.append(x)
        

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        if not self.empty():
            result = self.mylist[-1]
            del self.mylist[-1]
            return result
        

    def top(self) -> int:
        """
        Get the top element.
        """
        if not self.empty():
            return self.mylist[-1]
        

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        if not self.mylist:
            return True
        return False
        


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```