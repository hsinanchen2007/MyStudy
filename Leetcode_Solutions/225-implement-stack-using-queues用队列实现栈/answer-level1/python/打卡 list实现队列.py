### 解题思路
用列表模拟队列，没有特别考虑队列对应列表的顺序，相当于直接把列表末尾当成栈顶

### 代码

```python
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = []


    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.stack.append(x)



    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        self.element = self.stack[-1]
        del self.stack[-1]
        return self.element


    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self.stack[-1]



    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return True if len(self.stack)==0 else False



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```