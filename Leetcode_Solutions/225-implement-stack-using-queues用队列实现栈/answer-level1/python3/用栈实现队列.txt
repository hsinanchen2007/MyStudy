### 解题思路
此处撰写解题思路
python中可以使用列表来模拟队列和栈两种结构
队列和栈的进入方法相同：list.append()
出队列是list.pop(0) 出栈是list.pop(-1)
### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = []



    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.stack.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.stack.pop(-1)


    def top(self) -> int:
        """
        Get the top element.
        """
        return self.stack[-1]


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        if len(self.stack) == 0:
            return True
        else:
            return False



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```