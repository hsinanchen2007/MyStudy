### 解题思路
循环队列

### 代码

```python3
class MovingAverage:

    def __init__(self, size: int):
        """
        Initialize your data structure here.
        """
        self.capacity = size
        self.size = 0
        self.queue = [0] * self.capacity
        self.head = -1
        self.tail = -1
        

    def next(self, val: int) -> float:
        if self.head == -1:    #循环队列初始情况
            self.head, self.tail = 0, 0
            self.queue[self.tail] = val
            self.size += 1
            return val
        elif self.size < self.capacity:   #循环队列未满情况
            self.tail = (self.tail + 1) % self.capacity
            self.queue[self.tail] = val
            self.size += 1
            s_sum, index = 0, self.head
            
            for i in range(self.size):
                s_sum += self.queue[index]
                index = (index + 1) % self.capacity
            return s_sum/self.size
        else:                       #循环队列满了的情况
            self.tail = self.head
            self.head = (self.head + 1) % self.capacity
            self.queue[self.tail] = val
            return sum(self.queue)/self.capacity


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
```