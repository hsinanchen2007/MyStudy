### 解题思路
使用了`collections.deque()` 即`pytho`中的双边队列（double-ended queue）进行操作，它具备队列与栈的的功能。
初始化:新建一个`collections.deque()`
添加元素：使用`append`在队尾增加元素，类似于`list`的操作
弹出最顶端元素：使用`pop`直接弹出，默认为pop(-1)
取顶端元素：对于栈来说，顶端元素是最新加入的，也就是最末尾的元素。使用-1作为下标指定
检查是否为空：考虑队列中元素的个数，不为0则非空


### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = collections.deque([])


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.stack.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.stack.pop()


    def top(self) -> int:
        """
        Get the top element.
        """
        return self.stack[-1]  # for stack, top is the last element



    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.stack) == 0



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```