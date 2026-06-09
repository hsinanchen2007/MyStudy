### 解题思路
题意的意思就是维护一个单调队列，单调队列的出队位置维护队列内最大值，入队位置维护队列最小值。

### 代码

```python
class MaxQueue(object):

    def __init__(self):
        self.max_queue = []
        self.queue = []

    def max_value(self):
        """
        :rtype: int
        """
        if len(self.queue) == 0:
            return -1
        return self.max_queue[0]


    def push_back(self, value):
        """
        :type value: int
        :rtype: None
        """
        self.queue.append(value)
        while len(self.max_queue) and value > self.max_queue[-1]:
            del self.max_queue[-1]
        self.max_queue.append(value)

    def pop_front(self):
        """
        :rtype: int
        """
        if len(self.queue) == 0:
            return -1
        val = self.queue[0]
        if val == self.max_queue[0]:
            del self.max_queue[0]
        del self.queue[0]
        return val

# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```