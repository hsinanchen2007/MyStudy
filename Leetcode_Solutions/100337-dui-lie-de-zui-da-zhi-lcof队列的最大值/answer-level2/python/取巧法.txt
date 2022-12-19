### 解题思路
利用了list的特性

### 代码

```python
class MaxQueue(object):

    def __init__(self):
        self.list_=[]

    def max_value(self):
        """
        :rtype: int
        """
        if not self.list_:
            return -1
        else:
            return max(self.list_)

    def push_back(self, value):
        """
        :type value: int
        :rtype: None
        """
        self.list_.append(value)


    def pop_front(self):
        """
        :rtype: int
        """
        if not self.list_:
            return -1
        return self.list_.pop(0)



# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```