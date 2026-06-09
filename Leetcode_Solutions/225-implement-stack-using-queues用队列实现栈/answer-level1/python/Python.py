### 解题思路
此处撰写解题思路

### 代码

```python
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.ans=[]


    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.ans.append(x)


    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        if len(self.ans)==0:
            return False
        return self.ans.pop()

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        if len(self.ans)==0:
            return False
        return self.ans[len(self.ans)-1]

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        if len(self.ans)==0:
            return True
        return False

# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```