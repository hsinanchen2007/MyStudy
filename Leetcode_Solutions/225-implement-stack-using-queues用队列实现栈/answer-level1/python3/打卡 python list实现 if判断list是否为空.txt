### 解题思路

直接使用list来实现。
可以维护一个size变量，来保持现在栈内元素数目。
不过题目没让实现返回元素数目的方法，那么可以不用费劲去维护size。

```python
if a_list:
    #列表不为空
else:
    #列表为空
```


### 代码

```python
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

        return self.stack.pop()

    def top(self) -> int:
        """
        Get the top element.
        """
        return self.stack[-1]


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        if self.stack:
            return False
        return True
        

# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```