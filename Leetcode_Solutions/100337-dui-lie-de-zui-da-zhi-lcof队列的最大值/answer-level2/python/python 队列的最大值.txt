### 解题思路
此处撰写解题思路

### 代码

```python
class MaxQueue(object):

    def __init__(self):
        self.max_v = None
        self.values = []


    def max_value(self):
        """
        :rtype: int
        """
        
        if not self.values:
            return -1
        return self.max_v


    def push_back(self, value):
        """
        :type value: int
        :rtype: None
        """
        self.values.append(value)
        if self.max_v is None or value > self.max_v:
            self.max_v = value


    def pop_front(self):
        """
        :rtype: int
        """
        # if not self.values:
            # return -1
        value = -1
        if self.values:
            value = self.values[0]
            self.values.remove(value)
            if value == self.max_v:
                self.max_v = max(self.values) if self.values else -1
        return value



# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```