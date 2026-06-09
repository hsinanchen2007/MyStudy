### 解题思路
做的时候没注意Notes第三点，在pop和top操作时考虑了underflow的情况。用lists实现stack，无脑操作 十分简单...

### 代码

```python
class MyStack(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue=[] # simulate queue as list


    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        return self.queue.append(x)


    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        try:
            return self.queue.pop()
        except IndexError:
            print("Underflow!") 
        


    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        try:
            return self.queue[-1]
        except IndexError:
            print("Underflow!")

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        if len(self.queue)==0: 
            return True
        else:
            return False
       


