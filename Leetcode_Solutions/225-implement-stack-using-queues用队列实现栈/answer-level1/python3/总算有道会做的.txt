### 解题思路
使用列表实现栈，我们只需要搞清楚栈是后进先出(LIFO)，所以存数据和取数据都从列表的后面操作即可。
由于不要求检查列表是否为空，所以直接操作即可

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.arr = []

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        # 在最后添加元素，即压入栈
        self.arr.append(x)

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        # 弹出最后一个元素（列表pop默认就是弹出最后的元素）
        return self.arr.pop()


    def top(self) -> int:
        """
        Get the top element.
        """
        # 获取栈顶元素，直接返回最后一个元素
        return self.arr[-1]
        


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        # 是否为空，取反即可
        return  not self.arr
```
