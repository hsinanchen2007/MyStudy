### 解题思路
关键步骤：
  1. 数组需要保持一共空闲空间， 所以capacity = k + 1
  2. head 或 tail == capacity 时需要重置为0. 不然就不是环了， 会一直往后走
  3. 对空判断 head == tail, 这个很好理解
  4. 队满:  (tail + 1) % capacity == head
     a. tail + 1 == head 满足队满条件
     b. 反过来表示： tail = capacity - 1, head = 0  队满， 实际上就是一直入队， 此时： tail + 1 = capacity 而 head = 0 
        所以有： (tail + 1) % capacity == capacity % capacity == head == 0.
 5. 调试一下 跑几个用例， 看看数据会了然很多
        

### 代码

```python3
class MyCircularQueue(object):

    def __init__(self, k):

        """
        Initialize your data structure here. Set the size of the queue to be k.
        """
        self.capacity = k + 1
        self.queue = ['-' for i in range(self.capacity)]
        self.head = 0
        self.tail = 0

    def enQueue(self, value: int) -> bool:
        """
        Insert an element into the circular queue. Return true if the operation is successful.
        """
        if self.isFull():
            return False
        self.queue[self.tail] = value

        self.tail += 1
        if self.tail == self.capacity:
            self.tail = 0
        return True

    def deQueue(self) -> bool:
        """
        Delete an element from the circular queue. Return true if the operation is successful.
        """
        if self.isEmpty():
            return False
        self.queue[self.head] = '-'
        self.head += 1
        if self.head == self.capacity:
            self.head = 0
        return True

    def Front(self) -> int:
        """
        Get the front item from the queue.
        """
        if self.isEmpty():
            return -1
        return self.queue[self.head]

    def Rear(self) -> int:
        """
        Get the last item from the queue.
        """
        if self.isEmpty():
            return -1
        return self.queue[self.tail - 1]

    def isEmpty(self) -> bool:
        """
        Checks whether the circular queue is empty or not.
        """
        return self.tail == self.head

    def isFull(self) -> bool:
        """
        Checks whether the circular queue is full or not.
        """
        return (self.tail + 1) % self.capacity == self.head


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()
```