### 解题思路
两个栈表示队列

### 代码

```python
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.l=[]
    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.l.insert(0,x)

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        return self.l.pop(0)


    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self.l[0]


    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        if self.l is None or len(self.l)==0:
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