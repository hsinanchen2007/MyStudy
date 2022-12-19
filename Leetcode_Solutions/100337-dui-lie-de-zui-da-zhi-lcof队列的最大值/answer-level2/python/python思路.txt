### 解题思路
push_back 其实也是利用了队列先进先出的特性 因为如果先进队列的值小于当前要插入的值，那么这些小的值在主队列pop他们的时候是不影响最大值的变化
所以维护的 sort_queue 是一个由大到小递减的队列 当有更大的值插入时 把那些先插入队列较小的值可以pop出去了


### 代码

```python
from collections import deque
class MaxQueue(object):

    def __init__(self):
        self.queue = deque()
        self.sort_queue = deque()

    def max_value(self):
        """
        :rtype: int
        """
        return self.sort_queue[0] if self.sort_queue else -1

    def push_back(self, value):
        """
        :type value: int
        :rtype: None
        """
        self.queue.append(value)
        while self.sort_queue and self.sort_queue[-1] < value:
            self.sort_queue.pop()
        self.sort_queue.append(value)


    def pop_front(self):
        """
        :rtype: int
        """
        if not self.queue:
            return -1
        val = self.queue.popleft()
        if val == self.sort_queue[0]:
            self.sort_queue.popleft()
        return val 



# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```