### 解题思路
此处撰写解题思路

### 代码

```python
class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.MinStack=[]
        

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.MinStack.append(x)
        

    def pop(self):
        """
        :rtype: None
        """
        return self.MinStack.pop()
        

    def top(self):
        """
        :rtype: int
        """
        return self.MinStack[-1]
        

    def getMin(self):
        """
        :rtype: int
        """
        return min(self.MinStack)
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
```