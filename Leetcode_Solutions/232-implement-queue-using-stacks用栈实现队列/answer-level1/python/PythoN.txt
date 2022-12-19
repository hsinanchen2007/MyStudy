### 解题思路
此处撰写解题思路

### 代码

```python
class MyQueue(object):

    def __init__(self):
        self.myqueue=[]


    def push(self, x):
        """
        Push element x to the back of queue.
        :type x: int
        :rtype: None
        """
        self.myqueue.append(x)


    def pop(self):
        """
        Removes the element from in front of queue and returns that element.
        :rtype: int
        """
        if len(self.myqueue)==0:
            return False
        return self.myqueue.pop(0)


    def peek(self):
        """
        Get the front element.
        :rtype: int
        """
        #self.myqueue.peek(x)
        if len(self.myqueue)==0:
            return False
        return self.myqueue[0]

    def empty(self):
        """
        Returns whether the queue is empty.
        :rtype: bool
        """
        if len(self.myqueue)==0:
            return True
        else:
            return False



# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
```