### 解题思路
这题与 <求滑动窗口内的最大值> 是一样的 

### 代码

```python
from collections import deque
class MaxQueue(object):
    from collections import deque
    def __init__(self):
        self.deque_ = deque([])
        self.min_ = deque([])
        
    def max_value(self):
        """
        :rtype: int
        """
        if not self.min_:
            return -1
        else:
            return self.min_[0]

    def push_back(self, value):
        """
        :type value: int
        :rtype: None
        """
        self.deque_.extendleft([value])
        while self.min_ and self.min_[-1] < value:
            self.min_.pop()
        self.min_.append(value)
        
    def pop_front(self):
        """
        :rtype: int
        """
        if not self.deque_:
            return -1
        elif self.min_[0] == self.deque_[-1]:
            self.min_.popleft()
            return self.deque_.pop()
        else:
            return self.deque_.pop()




# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```