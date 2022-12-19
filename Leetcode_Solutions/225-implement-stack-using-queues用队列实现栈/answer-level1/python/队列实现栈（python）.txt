### 解题思路
此处撰写解题思路
用两个列表实现两个队列，一个主队列，一个辅助队列。
注意点：每个操作完成后，始终保持辅助队列为空。 
详情见代码。

### 代码

```python
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.A = []
        self.B = []
        

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.A.append(x)
        

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """ 
        if not self.B:
            while len(self.A) != 1:
                self.B.append(self.A.pop(0))
        self.A, self.B = self.B, self.A
        return self.B.pop(0)
        

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        if not self.B:
            while len(self.A) != 1:
                self.B.append(self.A.pop(0))
        self.A, self.B = self.B, self.A
        top_num = self.B[0]
        self.A.append(self.B.pop(0))
        return top_num



    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        if not self.A:
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