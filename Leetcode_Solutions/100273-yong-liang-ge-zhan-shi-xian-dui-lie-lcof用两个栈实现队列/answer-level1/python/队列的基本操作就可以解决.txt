### 解题思路
队列的基本操作就可以解决

### 代码

```python
class CQueue(object):

    def __init__(self):
        self.item = []

    def appendTail(self, value):
        """
        :type value: int
        :rtype: None
        """
        self.item.insert(0,value)

    def deleteHead(self):
        """
        :rtype: int
        """
        if len(self.item) == 0:
            return -1
        else:
            return self.item.pop()



# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()
```